var express = require('express');
var app = express();
app.use(express.static('static'));

app.route('/')
  .get(function(req, res) {
    res.sendFile('/home/daria/labs_sem7/web/lab2/server1/index.html');
  });

app.route('/temp/')
  .get(function(req, res) {
    res.status(200).send('This is temp page from first service!');
  })

var server = app.listen(8086, function () {
 	var host = server.address().address
 	var port = server.address().port
 	console.log('server 1 listening at http://%s:%s', host, port)
});