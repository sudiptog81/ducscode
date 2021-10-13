$(document).ready(function () {
  $('#styleToggle').click(function () {
    $('footer').addClass('footer').hide();

    $('*').css('font-family', 'Montserrat');
    $('body, html').css({
      'margin': '0',
      'padding': '0'
    });
    $('h2, p, ul, main').css('margin', '0');
    $('main').css('background', '#f2f2f2');

    $('h2').css('margin-bottom', '1rem');

    $('header').addClass('header');
    $('main > div').addClass('content');

    $('.pt-2').css('padding-top', '2rem');

    $('h2')
      .hide()
      .delay(500)
      .fadeIn('slow');

    $('h2')
      .next()
      .hide()
      .delay(500)
      .slideDown('slow');

    $('footer')
      .delay(500)
      .fadeIn('slow');

    $(this).remove();
  });
});
