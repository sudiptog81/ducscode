$(document).ready(function () {
  var flag = 'veg';
  $('#toggle').click(function () {
    $('#veg-menu').toggleClass('hidden');
    $('#non-veg-menu').toggleClass('hidden');
    if (flag === 'veg') {
      $('#breakfast-items>li').last().after('<li class="eggs">Eggs</li>');
      $('#dinner-items>li').last().after('<li class="eggs">Eggs</li>');
      $('.item-3').text('Non-veg Item 3');
      flag = 'non-veg';
    } else {
      $('.eggs').remove();
      $('.item-3').text('Item 3');
      flag = 'veg';
    }
  });
});
