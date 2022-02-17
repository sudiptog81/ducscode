const mysql = require('mysql');

const con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "root",
  database: "mydb"
});

con.connect(function (err) {
  if (err) throw err;
  con.query("SELECT * FROM customer WHERE CustCity = 'Delhi'", function (err, result, fields) {
    if (err) throw err;
    console.log(result);
  });
});
