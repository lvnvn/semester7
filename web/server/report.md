# Задание 1.
Замерьте скорость отдачи контента на сервере из лабораторной работы №1 (отдача страниц, картинки, запросов к api). Добавьте логирование приходящих запросов.

  ``` ab -n 10000 http://127.0.0.1:8080/  ```
  ```
Document Path:          /
Document Length:        1326 bytes

Concurrency Level:      1
Time taken for tests:   15.175 seconds
Complete requests:      10000
Requests per second:    658.98 [#/sec] (mean)
Time per request:       1.518 [ms] (mean)
Transfer rate:          1039.30 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.0      0       1
Processing:     1    1   0.5      1      14
Waiting:        0    1   0.4      1      14
Total:          1    1   0.5      1      14

Percentage of the requests served within a certain time (ms)
  50%      1
  66%      1
  75%      2
  80%      2
  90%      2
  95%      2
  98%      3
  99%      3
 100%     14 (longest request)
  ```

  ``` ab -c 100 -n 1000 http://127.0.0.1:8080/   ```
  ```
Document Path:          /
Document Length:        1326 bytes

Concurrency Level:      100
Time taken for tests:   1.243 seconds
Complete requests:      1000
Requests per second:    804.73 [#/sec] (mean)
Time per request:       124.265 [ms] (mean)
Time per request:       1.243 [ms] (mean, across all concurrent requests)
Transfer rate:          1269.18 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    1   1.8      0       8
Processing:    86  120  19.0    116     204
Waiting:       85  120  18.3    115     162
Total:         93  121  18.8    116     204

Percentage of the requests served within a certain time (ms)
  50%    116
  66%    129
  75%    136
  80%    138
  90%    153
  95%    158
  98%    160
  99%    161
 100%    204 (longest request)
  ```
## логирование

Логирование приходящих запросов в файл server.log с помощью log4s.

# Задание 2
Сконфигурируйте nginx сервер таким образом, чтобы запросы проходили через nginx и перенаправлялись на сервер из лабораторной работы №1.
# Задание 3
Используйте nginx отдачи статического контента. Как изменилось время ответа сервера?

nginx.conf:
(сервер из 1й лабраторной слушает порт 8081)
```
http {
    charset utf-8;
    server {
        listen 8080;
        location / {
            if ($request_method = GET ) {
            root /home/daria/labs_sem7/web/lab2/static;
            }
            if ($request_method = OPTIONS ) {
            proxy_pass http://localhost:8081;
            }
        }
        location /usr/ {
            proxy_pass http://localhost:8081;
        }
    }
}
  ```
  ``` ab -n 10000 http://127.0.0.1:8080/  ```
  ```
Document Path:          /
Document Length:        1333 bytes

Concurrency Level:      1
Time taken for tests:   2.975 seconds
Complete requests:      10000
Requests per second:    3360.80 [#/sec] (mean)
Time per request:       0.298 [ms] (mean)
Time per request:       0.298 [ms] (mean, across all concurrent requests)
Transfer rate:          5221.71 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.0      0       0
Processing:     0    0   0.1      0       2
Waiting:        0    0   0.1      0       2
Total:          0    0   0.1      0       2

Percentage of the requests served within a certain time (ms)
  50%      0
  66%      0
  75%      0
  80%      0
  90%      0
  95%      0
  98%      0
  99%      1
 100%      2 (longest request)
  ```
  ``` ab -c 100 -n 1000 http://127.0.0.1:8080/   ```
  ```
Document Path:          /
Document Length:        1333 bytes

Concurrency Level:      100
Time taken for tests:   0.144 seconds
Complete requests:      1000
Requests per second:    6928.28 [#/sec] (mean)
Time per request:       14.434 [ms] (mean)
Time per request:       0.144 [ms] (mean, across all concurrent requests)
Transfer rate:          10764.54 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        1    6   1.0      6       8
Processing:     3    8   2.1      8      18
Waiting:        2    6   2.0      7      17
Total:          6   14   2.0     14      22

Percentage of the requests served within a certain time (ms)
  50%     14
  66%     14
  75%     15
  80%     15
  90%     15
  95%     17
  98%     19
  99%     19
 100%     22 (longest request)
  ```
# Задание 4
Настройте кеширование и gzip сжатие файлов.  Как изменилось время ответа сервера?
nginx.conf:
  ```
  #main server
  server {
    listen 8082;

      location / {
      if ($request_method = GET ) {
        root /home/daria/labs_sem7/web/lab2/static;
      }
      if ($request_method = OPTIONS ) {
        proxy_pass http://127.0.0.1:8081;
      }
    }

    location /usr/ {
          proxy_pass http://127.0.0.1:8081/usr/;
      }
    }

  #caching server 
  server {
        listen 8080;
        location / {
            proxy_pass http://127.0.0.1:8082/;
            proxy_cache all;
            proxy_cache_valid any 1h;
        }
        location /usr/ {
            proxy_pass http://127.0.0.1:8082/usr/;
        }
  }

  gzip on;
  gzip_comp_level 6;
  gzip_types text/plain text/css application/json application/javascript text/xml application/xml application/xml+rss text/javascript;

  ```

  ``` ab -n 10000 http://127.0.0.1:8080/  ```
 ``` 
Document Path:          /
Document Length:        1333 bytes

Concurrency Level:      1
Time taken for tests:   4.350 seconds
Complete requests:      10000
Requests per second:    2299.06 [#/sec] (mean)
Time per request:       0.435 [ms] (mean)
Time per request:       0.435 [ms] (mean, across all concurrent requests)
Transfer rate:          3572.07 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        0    0   0.0      0       1
Processing:     0    0   0.1      0       5
Waiting:        0    0   0.1      0       5
Total:          0    0   0.1      0       5

Percentage of the requests served within a certain time (ms)
  50%      0
  66%      0
  75%      0
  80%      0
  90%      0
  95%      1
  98%      1
  99%      1
 100%      5 (longest request)
   ``` 
  ``` ab -c 100 -n 1000 http://127.0.0.1:8080/   ```
  ``` 
  Document Path:          /
Document Length:        1333 bytes

Concurrency Level:      100
Time taken for tests:   0.150 seconds
Complete requests:      1000
Requests per second:    6673.43 [#/sec] (mean)
Time per request:       14.985 [ms] (mean)
Time per request:       0.150 [ms] (mean, across all concurrent requests)
Transfer rate:          10368.58 [Kbytes/sec] received

Connection Times (ms)
              min  mean[+/-sd] median   max
Connect:        2    6   1.1      6       9
Processing:     2    9   2.6      9      19
Waiting:        1    7   2.5      7      16
Total:          9   14   2.2     14      22

Percentage of the requests served within a certain time (ms)
  50%     14
  66%     15
  75%     15
  80%     15
  90%     17
  95%     19
  98%     20
  99%     22
 100%     22 (longest request)

  ``` 
# Задание 5
Запустите еще 2 инстанса вашего сервера из лабораторной работы №1, настройте перенаправление таким образом, чтобы на серверы приходили запросы в соотношении 3:1. 

instance 1 server listening at http://:::8083
instance 2 server listening at http://:::8084
instance 3 server listening at http://:::8085

nginx.conf:
  ``` 
upstream backend  {
    server 127.0.0.1:8083 weight=3;
    server 127.0.0.1:8084 weight=1;
    server 127.0.0.1:8085 weight=1;
  }
  ```
# Задание 6
Напишите еще два мини-сервера. Каждый из них должен обрабатывать два GET-запроса.
по / отдавать страницу с надписью “Добро пожаловать на сервис #1/#2” и ссылкой, ведущей на /temp
по /temp  возвращать произвольный контент
Настройте nginx так, чтобы в дополнение к п.1-5 он перенаправлял запросы по url /service1 и /service2 на соответствующие сервера. 
 
nginx.conf:
(мини-сервера #1 и #2 слушают порты 8086 и 8087 соответственно)
  ``` 
location /service1/ {          
  proxy_pass http://localhost:8086/;
}
location /service2/ {          
  proxy_pass http://localhost:8087/;
}
  ```
# Задание 7
Настройте отдачу страницы о состоянии сервера
  ```
 location = /status {
        stub_status;
    }
  ```