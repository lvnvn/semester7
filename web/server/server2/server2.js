var express = require('express');
var app = express();
app.use(express.static('static'));

app.route('/')
  .get(function(req, res) {
    res.sendFile('/home/daria/labs_sem7/web/lab2/server2/index.html');
  });

app.route('/temp/')
  .get(function(req, res) {
    res.status(200).send('This is temp page from second service!');
  })

var server = app.listen(8087, function () {
 	var host = server.address().address
 	var port = server.address().port
 	console.log('server 2 listening at http://%s:%s', host, port)
});