1. 	Cài xong Qt.
2. 	Tải MySql.
	link: http://dev.mysql.com/downloads/file/?id=462316 (kéo xuống dưới click No thanks....).
3. 	Cài bình thường, chú ý name với password. Cài xong để đó. Tại vì không sài trực tiếp nó.
4. 	Không biết sao Qt không có hỗ trợ sẵn cái vụ SqlDatabase, muốn có phải build, mà search quài hk ra. Nên xài phần mềm hỗ trợ. 
	Cài MariaDB. Cái này như là phần trung gian giao tiếp giữa MySQL với Qt.
	Link: https://downloads.mariadb.org/ (tải cái MariaDB 10.1 Series -> mariadb-10.1.13-winx64.msi)
5. 	Cài MariaDB.
	Hình như cứ để mạc định. Chổ change password root gì đó thì để ý chút... đặt pass giống với bước 3 cho dễ nhớ 
6.	Cài xong mở cái HeidiSQL lên.
	Bên Session name chọn New, đặt tên cho nó ("test")
	Network type: MySQL (TCP/IP)
	Hostname/IP: localhost
	User: root
	Password: pass lúc nãy đặt
	Port: mạc định cho MySql là 3306
	click Open
7. 	Chọn tab Query
	paste cái quỷ này vào
	
CREATE DATABASE TEST1;
USE TEST1;

CREATE TABLE TABLE1
(
	ID INT PRIMARY KEY,
	WORD NVARCHAR(10)
);

INSERT INTO TABLE1 VALUES(1, N'MỘT');
INSERT INTO TABLE1 VALUES(2, N'HAI');
INSERT INTO TABLE1 VALUES(3, N'BA');
INSERT INTO TABLE1 VALUES(4, N'BỐN');
	
	xong execute,
	xong refresh,
	mở cái table1 trong test1 ra,
	bên phải sẽ có thêm tab Data,
	Thấy dữ liệu được nhập rồi thì ok

Từ đây trở đi tham khảo source code kèm theo
8.	Mở Qt Creator.
	Tạo Qt Widgets Application, tới chỗ Base class chọn Qwidgets
9. 	sửa dòng "QT       += core gui" thành "QT       += core gui sql"
10. 	Vẽ ui bao gồm:
		+ Table View
		+ Push Button: tạo xong click phải chọn go to slot->ok để tạo phương thức
11.	Xong chạy sẽ bị lỗi chỗ addDatabase("QMYSQL"
	Vào C:\Program Files\MariaDB 10.1\lib
	Coppy file libmysql.dll bỏ vào thư mục build ( thư mục build-<tên project>-.....)
12	Hình như hết rồi