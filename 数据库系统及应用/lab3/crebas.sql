-- Active: 1685774839374@@127.0.0.1@3306@lab3

/*==============================================================*/

/* DBMS name:      MySQL 5.0                                    */

/* Created on:     2023/5/24 16:13:23                           */

/*==============================================================*/

drop table if exists Course;

drop table if exists HaveProject;

drop table if exists Paper;

drop table if exists PostPaper;

drop table if exists Project;

drop table if exists TeachCourse;

drop table if exists teacher;

drop table if exists accountinfo;

create table
    accountinfo(
        ac char(255) not null,
        passwd char(255) not null,
        primary key(ac)
    );

/*==============================================================*/

/* Table: Course                                                */

/*==============================================================*/

create table
    Course (
        CourseID char(255) not null,
        CourseName char(255),
        CourseTime int,
        CourseType int,
        primary key (CourseID)
    );

/*==============================================================*/

/* Table: HaveProject                                           */

/*==============================================================*/

create table
    HaveProject (
        TeacherNum char(5) not null,
        ProjectID char(255) not null,
        HaveRank int,
        HaveCost float,
        primary key (TeacherNum, ProjectID)
    );

/*==============================================================*/

/* Table: Paper                                                 */

/*==============================================================*/

create table
    Paper (
        PaperID int not null,
        PaperName char(255),
        PaperFrom char(255),
        PaperYear date,
        PaperType int,
        PaperLevel int,
        primary key (PaperID)
    );

/*==============================================================*/

/* Table: PostPaper                                             */

/*==============================================================*/

create table
    PostPaper (
        TeacherNum char(5) not null,
        PaperID int not null,
        PostRank int,
        IsAuthor bool,
        primary key (TeacherNum, PaperID)
    );

/*==============================================================*/

/* Table: Project                                               */

/*==============================================================*/

create table
    Project (
        ProjectID char(255) not null,
        ProjectName char(255),
        ProjectFrom char(255),
        ProjectType int,
        ProjectCost float,
        ProjectBegin int,
        ProjectEnd int,
        primary key (ProjectID)
    );

/*==============================================================*/

/* Table: TeachCourse                                           */

/*==============================================================*/

create table
    TeachCourse (
        TeacherNum char(5) not null,
        CourseID char(255) not null,
        TeachYear int,
        TeachTerm int,
        TeachTime int,
        primary key (TeacherNum, CourseID, TeachYear,TeachTerm)
    );

/*==============================================================*/

/* Table: teacher                                               */

/*==============================================================*/

create table
    teacher (
        TeacherNum char(5) not null,
        TeacherName char(255),
        TeacherSex int,
        TeacherJob int,
        primary key (TeacherNum)
    );

alter table HaveProject
add
    constraint FK_HaveProject foreign key (TeacherNum) references teacher (TeacherNum) on delete restrict on update restrict;

alter table HaveProject
add
    constraint FK_HaveProject2 foreign key (ProjectID) references Project (ProjectID) on delete restrict on update restrict;

alter table PostPaper
add
    constraint FK_PostPaper foreign key (TeacherNum) references teacher (TeacherNum) on delete restrict on update restrict;

alter table PostPaper
add
    constraint FK_PostPaper2 foreign key (PaperID) references Paper (PaperID) on delete restrict on update restrict;

alter table TeachCourse
add
    constraint FK_TeachCourse foreign key (TeacherNum) references teacher (TeacherNum) on delete restrict on update restrict;

alter table TeachCourse
add
    constraint FK_TeachCourse2 foreign key (CourseID) references Course (CourseID) on delete restrict on update restrict;