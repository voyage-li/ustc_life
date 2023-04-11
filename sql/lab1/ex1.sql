create database if not exists lab1;

use lab1;

drop table if exists `Borrow`;
drop table if exists `Book`;
drop table if exists `Reader`;  
drop table if exists `Reserve`;  


create table `lab1`.`Book`(
    `ID` char(8) not null,
    `name` varchar(10) not null,
    `author` varchar(10) default null,
    `price` float,
    `status` int default 0,
    `borrowTimes` int default 0,
    `reserveTimes` int default 0, 
    primary key(`ID`),
    check(`status` in (0,1,2,3))
);

create table `lab1`.`Reader`(
    `ID` char(8) not null,
    `name` varchar(10) not null,
    `age` int,
    `addresss` varchar(20),
    primary key(`ID`)
);

create table `lab1`.`Borrow`(
    `bookID` char(8) not null,
    `readerID` char(8) not null,
    `borrowDate` date not null,
    `returnDate` date,
    primary key(`borrowDate`,`bookID`,`readerID`),
    foreign key(`bookID`) references `lab1`.`Book` (`ID`),
    foreign key(`readerID`) references `lab1`.`Reader` (`ID`)
);

create table `lab1`.`Reserve`(
    `bookID` char(8) not null,
    `readerID` char(8) not null,
    `reserveDate` date not null,
    `takeDate` date,
    primary key(`bookID`,`readerID`,`reserveDate`),
    check (`reserveDate` < `takeDate`)
);