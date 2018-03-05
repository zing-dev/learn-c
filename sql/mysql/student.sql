
create table if not exists `student` (
    `id` int auto_increment,
    `name` varchar(16) not null,
    `age` int not null,
    `address` varchar(128) not null,
    primary key (`id`)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;