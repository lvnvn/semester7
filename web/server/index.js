var express = require('express');
var app = express();
app.use(express.static('static'));

const log4js = require('log4js');
log4js.configure({
appenders: { server: { type: 'file', filename: 'server.log' } },
categories: { default: { appenders: ['server'], level: 'debug' } }
});
const logger = log4js.getLogger('server');
logger.debug('logging is on');

 
var userArray = new Array(0);
userArray.push({name: 'вася', surname: 'пупкин'});
userArray.push({name: 'иван', surname: 'иванов'});
userArray.push({name: 'петр', surname: 'петров'});


app.route('/')
  .get(function(req, res) {
    logger.debug('get request at /');
    res.writeHead(200, {
  	'Content-Type': 'application/json,charset=utf-8',
  	'Cache-Control': 'no-cache, no-store, must-revalidate'
    });
    res.sendFile(index.html);
    res.end();
  })
  .options(function(req, res) {
  	logger.debug('options request at /');
    res.writeHead(200, {
  	'Content-Type': 'application/json',
  	'Cache-Control': 'no-cache',
  	'Allow': 'GET,OPTIONS,POST,DELETE,PUT'
  	});
  	res.end();
  });

app.route('/usr/')
  .get(function(req, res) {
    logger.debug('get request  at /usr');
  	count = req.query.count;
  	offset = req.query.offset;
  	var newArray = userArray;
  	if (offset != undefined){
  		newArray = newArray.slice(offset);
  	}
  	if(count != undefined){
  		newArray = newArray.slice(0,count);
  	}
    res.status(200).json({users: newArray});
  })
  .post(function(req, res) {
    logger.debug('post request at /usr');
    name = req.query.name;
    surname = req.query.surname;
    if(name === undefined || surname === undefined){
    	res.status(206).json({error: 'Для создания пользователя необходимы имя и фамилия'});
    	res.end();
    }
    
    user = new Object();
	user.name = name;
	user.surname = surname;
	if(userArray.findIndex(x => x.name==user.name&&x.surname==user.surname) != -1){
    	res.status(403).json({error: 'Этот пользователь уже существует'});
    	res.end();
	} else {
	userArray.push(user);
    res.status(201).json({name: name, surname: surname});
    res.end();
	}
  })
  .delete(function(req, res) {
    logger.debug('delete request at /usr');
    name = req.query.name;
    surname = req.query.surname;
    if(name === undefined || surname === undefined)
    	res.status(206).json({error: 'Для удаления пользователя необходимы имя и фамилия'});

    user = new Object();
	user.name = name;
	user.surname = surname;
	var index = userArray.findIndex(x => x.name==user.name&&x.surname==user.surname);
	if(index == -1){
		res.status(404).json({error: 'Такого пользователя не существует'});
	} else {
		userArray = userArray.slice(0,index).concat(userArray.slice(index+1));
		res.status(200).json({deleted: user});
	}

  })
  .put(function(req, res) {
    logger.debug('put request at /usr');
  	name = req.query.name;
    surname = req.query.surname;
    newname = req.query.newname;
    newsurname = req.query.newsurname;

    if(name === undefined || surname === undefined)
    	res.status(206).json({error: 'Для изменения пользователя необходимы имя и фамилия'});

    user = new Object();
	user.name = name;
	user.surname = surname;

	if(userArray.findIndex(x => x.name==user.name&&x.surname==user.surname) == -1)
		res.status(404).json({error: 'Такого пользователя нет:',user: user});

	if(newname === undefined && newsurname === undefined)
		res.status(206).json({error: 'Нет данных для изменения'});

	newuser = new Object();
	if(newname != undefined)
		newuser.name = newname;
	else
		newuser.name = name;
	if(newsurname != undefined)
		newuser.surname = newsurname;
	else
		newuser.surname = surname;

	if(userArray.findIndex(x => x.name==newuser.name&&x.surname==newuser.surname) != -1)
		res.status(409).json({error: 'Такой пользователь уже существует:',user: newuser});
	else{
		userArray[userArray.findIndex(x => x.name==user.name&&x.surname==user.surname)] = newuser;
		res.status(200).json({user: user, newuser:newuser});
	}

  });
	

 
var server1 = app.listen(8083, function () {
 	var host = server1.address().address
 	var port = server1.address().port
 	console.log('instance 1 server listening at http://%s:%s', host, port)
});
var server2 = app.listen(8084, function () {
  var host = server2.address().address
  var port = server2.address().port
  console.log('instance 2 server listening at http://%s:%s', host, port)
});
var server3 = app.listen(8085, function () {
  var host = server3.address().address
  var port = server3.address().port
  console.log('instance 3 server listening at http://%s:%s', host, port)
});
 
