CREATE TABLE activeuser(
userid integer,
shortcode varchar(10)
);

CREATE TABLE historylogs(
historylogid integer primary key autoincrement,
description text,
userid integer references users (userid),
insertedon datetime DEFAULT(DATETIME(CURRENT_TIMESTAMP, 'localtime'))
);

CREATE TABLE modules(
moduleid integer primary key autoincrement,
modulename varchar(40)
);

CREATE TABLE userpermissions(
userpermissionid integer primary key autoincrement,
userid integer references users(userid),
moduleid integer references modules(moduleid),
insertedon datetime DEFAULT(DATETIME(CURRENT_TIMESTAMP, 'localtime'))
);

CREATE TABLE users(
userid integer primary key autoincrement,
login varchar(20),
password varchar(20) default 0,
insertedon default (((julianday('now') - 2440587.5)*86400.0) || abs(random())),
lastsuccessfullogin datetime default '',
lastfailedlogin datetime default '',
failcounter integer,
shortcode  varchar(10)
);

INSERT INTO users (login, password, insertedon, failcounter) values ('superadmin', '6A423509AA3F572E44DC8A3465C22EA038BCEB00C10397351E664B77C86F4801', '1396507367.1863558866053569960755', 0);

INSERT INTO modules (modulename) values ('Add User');
INSERT INTO modules (modulename) values ('Modify Privileges');
INSERT INTO modules (modulename) values ('Rates');
INSERT INTO modules (modulename) values ('Shortcodes');
INSERT INTO modules (modulename) values ('Survivor Recording');
INSERT INTO modules (modulename) values ('Config Settings');
INSERT INTO modules (modulename) values ('History Logs');
INSERT INTO modules (modulename) values ('Modify User');
INSERT INTO modules (modulename) values ('Community Alerts');

INSERT INTO userpermissions (userid, moduleid) values (1, 2);
