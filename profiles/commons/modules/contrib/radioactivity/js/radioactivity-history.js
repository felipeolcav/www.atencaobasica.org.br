(function ($) {
Drupal.behaviors.radioactivity = {

  config: '',
  activeIncidents: Array(),

  attach: function (context, settings) {

    if ($.fn.sparkline) {
      $('.radioactivity-history').each(function () {
        var dataset = $.parseJSON($(this).text());
        $('.radioactivity-history').sparkline(dataset.values, {
          type:'bar',
          height:'100%',
          width:'100%',
          chartRangeMin: dataset.cutoff,
          tooltipFormat: dataset.tooltipFormat,
          tooltipValueLookups: {
            tooltips: dataset.tooltips
          } 
        });
      });
    }
  }
};
})(jQuery);
