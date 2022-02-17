const form = document.querySelector("form");
form.addEventListener("submit", function (e) {
  e.preventDefault();
  let index = document.querySelector("#index").value;
  let property = document.querySelector("#property").value;
  if (index < 0 || index >= parks.length) {
    alert("Index is out of range");
  }
  let park = parks[index];
  if (!park.hasOwnProperty(property)) {
    alert("Property not found");
  }
  let value = park[property];
  document.getElementById("result").innerText = `Result: ${value}`;
});
