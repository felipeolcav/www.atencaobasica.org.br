function dabProject (){


}

jQuery( document ).ready(function() {

  jQuery( '#edit-field-cidade-und' ).attr('size','10');

  jQuery('body').append("<select id='invisibleContainer' style='display: none;'></select>");

  jQuery( '#edit-field-estado-und' ).change(function(){

    jQuery( '#edit-field-cidade-und > option' ).appendTo('#invisibleContainer');
    jQuery( '#invisibleContainer > option[value*="' + this.value + '"]' ).appendTo('#edit-field-cidade-und');

  });
});