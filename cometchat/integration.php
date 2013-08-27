<?php

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ADVANCED */

define('SET_SESSION_NAME','');			// Session name
define('DO_NOT_START_SESSION','0');		// Set to 1 if you have already started the session
define('DO_NOT_DESTROY_SESSION','0');	// Set to 1 if you do not want to destroy session on logout
define('SWITCH_ENABLED','0');
define('INCLUDE_JQUERY','1');
define('FORCE_MAGIC_QUOTES','0');

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* DATABASE */

 if(!file_exists(dirname(dirname(__FILE__)).DIRECTORY_SEPARATOR.'sites'.DIRECTORY_SEPARATOR.'default'.DIRECTORY_SEPARATOR.'settings.php')) {
  echo "Please check if cometchat is installed in the correct directory.<br /> The 'cometchat' folder should be placed at <DRUPAL_HOME_DIRECTORY>/cometchat";
  exit;
 }
try {
 include_once(dirname(dirname(__FILE__)).DIRECTORY_SEPARATOR.'sites'.DIRECTORY_SEPARATOR.'default'.DIRECTORY_SEPARATOR.'settings.php');
 ini_set('session.save_handler','files');

} catch (Exception $e) {
// algo ocorreu errado ao carregar as configurações do drupal
}

$db_url = $databases['default']['default'];

$db = $databases['default']['default']["database"];

$host = $databases['default']['default']["host"];

$user = $databases['default']['default']['username'];
$pwd = $databases['default']['default']['password'];

$db_prefix = $databases['default']['default']['prefix'];

// DO NOT EDIT DATABASE VALUES BELOW

define('DB_SERVER',					$host								     );
define('DB_PORT',					"3306"									 );
define('DB_USERNAME',				$user									 );
define('DB_PASSWORD',				$pwd								     );
define('DB_NAME',					$db								         );
define('TABLE_PREFIX',				$db_prefix								 );
define('DB_USERTABLE',				"users"									 );
define('DB_USERTABLE_NAME',			"name"							         );
define('DB_USERTABLE_USERID',		"uid"								     );
define('DB_AVATARTABLE',		    " left join ".TABLE_PREFIX."file_managed on ".TABLE_PREFIX."file_managed.fid = ".TABLE_PREFIX.DB_USERTABLE.".picture" );
define('DB_AVATARFIELD',		    " ".TABLE_PREFIX."file_managed.filename	");
define('DB_USERTABLE_LASTACTIVITY',	"lastactivity"							 );
define('ADD_LAST_ACTIVITY',			"1"							 			 );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* FUNCTIONS */

function getUserID() {
	$userid = 0;
	if (!empty($_SESSION['basedata']) && $_SESSION['basedata'] != 'null') {
		$_REQUEST['basedata'] = $_SESSION['basedata'];
	}

	if (!empty($_REQUEST['basedata'])) {
		if (function_exists('mcrypt_encrypt')) {
			$key = KEY_A.KEY_B.KEY_C;
			$uid = rtrim(mcrypt_decrypt(MCRYPT_RIJNDAEL_256, md5($key), base64_decode($_REQUEST['basedata']), MCRYPT_MODE_CBC, md5(md5($key))), "\0");
			if (intval($uid) > 0) {
				$userid = $uid;
			}
		} else {
			$userid = $_REQUEST['basedata'];
		}
	}

	$sess_id = getSessionId();
	foreach ($_COOKIE as $key=>$val) {
		if(strpos($key, 'SESS') === 0) {
		$sess_id = $val;
			if(!empty($sess_id)) {
				$result = mysql_query("SELECT uid FROM ".TABLE_PREFIX."sessions WHERE sid = '".mysql_real_escape_string($sess_id)."'");
				if($row=mysql_fetch_array($result)) {
					if (!empty($row['uid'])) {
						$userid = $row['uid'];
					}
				}
			}
		}
	}

	$userid = intval($userid);
	return $userid;
}

function chatLogin($userName,$userPass) {
	$userid = 0;
	if (filter_var($userName, FILTER_VALIDATE_EMAIL)) {
		$sql = ("SELECT * FROM ".TABLE_PREFIX.DB_USERTABLE." WHERE mail ='".$userName."'");
	} else {
		$sql = ("SELECT * FROM ".TABLE_PREFIX.DB_USERTABLE." WHERE name ='".$userName."'");
	}
	$result = mysql_query($sql);
	$row = mysql_fetch_array($result);

	if ($row['pass'] == md5($userPass)) {
		$userid = $row['uid'];
	}
	if ($userid && function_exists('mcrypt_encrypt')) {
		$key = KEY_A.KEY_B.KEY_C;
		$userid = base64_encode(mcrypt_encrypt(MCRYPT_RIJNDAEL_256, md5($key), $userid, MCRYPT_MODE_CBC, md5(md5($key))));
	}

	return $userid;
}

function getFriendsList($userid,$time) {
	$sql = ("select DISTINCT ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." userid, ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_NAME." username, ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_LASTACTIVITY." lastactivity, " .DB_AVATARFIELD. " avatar, ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." link, cometchat_status.message, cometchat_status.status from ".TABLE_PREFIX.DB_USERTABLE." left join cometchat_status on ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." = cometchat_status.userid ".DB_AVATARTABLE." where ('".mysql_real_escape_string($time)."'-".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_LASTACTIVITY." < '".((ONLINE_TIMEOUT)*2)."') and (cometchat_status.status IS NULL OR cometchat_status.status <> 'invisible' OR cometchat_status.status <> 'offline') order by username asc");

	return $sql;
}

function getFriendsIds($userid) {
	$sql = ("select group_concat(friends.fid) myfrndids from (select ".TABLE_PREFIX."friends.friend_user_id fid from ".TABLE_PREFIX."friends where ".TABLE_PREFIX."friends.initiator_user_id = '".mysql_real_escape_string($userid)."' and is_confirmed = 1 union select ".TABLE_PREFIX."friends.initiator_user_id fid from ".TABLE_PREFIX."friends where ".TABLE_PREFIX."friends.friend_user_id = '".mysql_real_escape_string($userid)."' and is_confirmed = 1) friends");

	return $sql;
}

function getUserDetails($userid) {
	$sql = ("select ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." userid, ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_NAME." username, ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_LASTACTIVITY." lastactivity,  ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." link,  ".DB_AVATARFIELD." avatar, cometchat_status.message, cometchat_status.status from ".TABLE_PREFIX.DB_USERTABLE." left join cometchat_status on ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." = cometchat_status.userid ".DB_AVATARTABLE." where ".TABLE_PREFIX.DB_USERTABLE.".".DB_USERTABLE_USERID." = '".mysql_real_escape_string($userid)."'");

	return $sql;
}

function updateLastActivity($userid) {
	$sql = ("update `".TABLE_PREFIX.DB_USERTABLE."` set ".DB_USERTABLE_LASTACTIVITY." = '".getTimeStamp()."' where ".DB_USERTABLE_USERID." = '".mysql_real_escape_string($userid)."'");

	return $sql;
}

function getUserStatus($userid) {
	$sql = ("select cometchat_status.message, cometchat_status.status from cometchat_status where userid = '".mysql_real_escape_string($userid)."'");

	return $sql;
}

function fetchLink($link) {
    return '';
}

function getAvatar($image) {
if($image)
	{
		return BASE_URL.'../sites/default/files/styles/thumbnail/public/pictures/'.$image;

	}
	else{

		return BASE_URL.'/images/noavatar.gif';
	}

}


function getTimeStamp() {
	return time();
}

function processTime($time) {
	return $time;
}

if (!function_exists('getLink')) {
  	function getLink($userid) {
		return fetchLink($userid);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* HOOKS */

function hooks_statusupdate($userid,$statusmessage) {

}

function hooks_forcefriends() {

}

function hooks_activityupdate($userid,$status) {

}

function hooks_message($userid,$to,$unsanitizedmessage) {

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* LICENSE */

include_once(dirname(__FILE__).DIRECTORY_SEPARATOR.'license.php');
$x="\x62a\x73\x656\x34\x5fd\x65c\157\144\x65";
eval($x('JHI9ZXhwbG9kZSgnLScsJGxpY2Vuc2VrZXkpOyRwXz0wO2lmKCFlbXB0eSgkclsyXSkpJHBfPWludHZhbChwcmVnX3JlcGxhY2UoIi9bXjAtOV0vIiwnJywkclsyXSkpOw'));


function getSessionId() {
  foreach ($_COOKIE as $key=>$val) {
	  if (strpos($key, 'SESS') === 0) {
		  return $val;
	  }
  }
  return '';
}
