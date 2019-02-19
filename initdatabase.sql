use mysql;
insert into user(host, user, password) values('localhost', 'user', password('123445');

create database LibraryManageSystem;
use LibraryManageSystem;

create table users (
    id int(8),
    name char(10),
    password char(10));
insert into users (id, name, password) values (0, 'root', 'root');
insert into users (id, name, password) values (1, 'xhq1', 'xhq1');
insert into users (id, name, password) values (2, 'xhq2', 'xhq2');
insert into users (id, name, password) values (3, 'xhq3', 'xhq3');

create table userBooks (
	userId int(8),
	bookId int(8),
    year int(8),
	mouth int(2),
	day int(3));
insert into userBooks (userId, bookId, year, mouth, day) values (1, 1, 2017, 1, 1);
insert into userBooks (userId, bookId, year, mouth, day) values (1, 4, 2018, 2, 6);
insert into userBooks (userId, bookId, year, mouth, day) values (2, 3, 2017, 2, 2);
insert into userBooks (userId, bookId, year, mouth, day) values (2, 4, 2018, 4, 16);

create table books (
	id int(8),
	name char(20),
	author char(20),
	category char(20),
	introduction varchar(200)) default charset=utf8;
	
insert into books (id, name, author, category, introduction) values (1, '飞剑问道', '我吃西红柿', '仙侠', '在这个世界，有狐仙、河神、水怪、大妖，也有求长生的修行者。修行者们，开法眼，可看妖魔鬼怪。炼一口飞剑，可千里杀敌。千里眼、顺风耳，更可探查四方。……秦府二公子‘秦云’，便是一位修行');
insert into books (id, name, author, category, introduction) values (2, '我是仙凡', '百里玺', '仙侠', '仙侠和种田结合。一名少年无意打开灵台，识海发现方寸灵山。从此种仙稻，养灵药，开洞府，开辟一片桃源仙境，踏上修仙之路。-------------------百里玺官方粉丝群：3328');
insert into books (id, name, author, category, introduction) values (3, '斗战狂潮', '骷髅精灵', '仙侠', '双月当空，无限可能的英魂世界孤寂黑暗，神秘古怪的嬉命小丑百城联邦，三大帝国，异族横行，魂兽霸幽这是一个英雄辈出的年代，人类卧薪尝胆重掌地球主权，孕育着进军高纬度的野望！重点是……二');
insert into books (id, name, author, category, introduction) values (4, '龙皇武神', '步征', '都市', '都市修仙至尊爽文！渡劫期大修士凌云魂穿都市，仙武同修，丹药、炼器，画符，布阵无所不能，以无敌之姿逆天崛起，脚踩八方！');
insert into books (id, name, author, category, introduction) values (5, '太初', '高楼大厦', '玄幻', '一树生的万朵花，天下道门是一家。法术千般变化，人心却亘古不变');
insert into books (id, name, author, category, introduction) values (6, '伏天氏', '净无痕', '玄幻', '东方神州，有人皇立道统，有圣贤宗门传道，有诸侯雄踞一方王国，诸强林立，神州动乱千万载，值此之时，一代天骄叶青帝及东凰大帝横空出世，斩人皇，驭圣贤，诸侯臣服，东方神州一统！然，叶青帝');
insert into books (id, name, author, category, introduction) values (7, '万界天尊', '血红', '玄幻', '天为何物？高高在上，威严莫测，是法则，是戒律，是无情，是冷酷。天意，何也？俯瞰众生，操持风云，褫夺赏罚，随性而为。故，天意不可测，苍天不可近。顺之应之，未必得其利；逆之叛之，福祸却');
insert into books (id, name, author, category, introduction) values (8, '苍穹之上', '石三', '仙侠', '苍穹之下的千年苦修，只为有朝一日立身于苍穹之上！位于洪武天朝和妖族七杀部咽喉要地的天断峡谷中，忽有天降神异之物，裹挟着一众修兵，滚入了浩荡的历史洪流当中……宋征只是其中不那么起眼的');
insert into books (id, name, author, category, introduction) values (9, '无疆', '小刀锋利', '仙侠', '鹰击长空，鱼跃龙门，熊咆虎啸，万物皆有灵。末法之极，磁极轮转，世界变迁。曾经那个熟悉的世界，已经变得面目全非。当神话变成现实，当传说不再神秘，世界无疆，热血永恒。');
insert into books (id, name, author, category, introduction) values (10, '圣墟', '辰东', '玄幻', '在破败中崛起，在寂灭中复苏。沧海成尘，雷电枯竭，那一缕幽雾又一次临近大地，世间的枷锁被打开了，一个全新的世界就此揭开神秘的一角……');
insert into books (id, name, author, category, introduction) values (11, '还看今朝', '瑞根', '都市', '当扑面而来的时代巨澜把懵懵懂懂的沙正阳卷入其中时，他是随波逐流，风花雪月，还是长缨在手，逆流击波？干想干的事，为恣意人生。做该做的事，为家国情怀。一万年太久，只争朝夕！到中流击水，');
insert into books (id, name, author, category, introduction) values (12, '凡人修仙之仙界篇', '忘语', '仙侠', '凡人修仙，风云再起时空穿梭，轮回逆转金仙太乙，大罗道祖三千大道，法则至尊《凡人修仙传》仙界篇，一个韩立叱咤仙界的故事，一个凡人小子修仙的不灭传说。特说明下，没有看过前传的书友，并不');
insert into books (id, name, author, category, introduction) values (13, '大王饶命', '会说话的肘子', '都市', '灵气复苏的时代，寂静生活碎掉了，仿佛雷霆贯穿长空，电光直射天心，雨沙沙地落下。凡逆我们的终将死去，这就是法则。……这是一个吕树依靠毒鸡汤成为大魔王的故事。');
insert into books (id, name, author, category, introduction) values (14, '汉乡', '孑与2', '历史', '我们接受了祖先的遗产，这让中华辉煌了数千年，我们是如此的心安理得，从未想过要回归那个在刀耕火种中苦苦寻找出路的时代。反哺我们苦难的祖先，并从中找到故乡的真正意义，将是本书要讲的故事');
insert into books (id, name, author, category, introduction) values (15, '修真聊天群', '圣骑士的传说', '都市', '某天，宋书航意外加入了一个仙侠中二病资深患者的交流群，里面的群友们都以‘道友’相称，群名片都是各种府主、洞主、真人、天师。连群主走失的宠物犬都称为大妖犬离家出走。整天聊的是炼丹、闯');
insert into books (id, name, author, category, introduction) values (16, '别玩网游', '尝谕', '都市', '新书请到这里。大家先收藏，新书发布时间待定。');
insert into books (id, name, author, category, introduction) values (17, '深夜书屋', '纯洁滴小龙', '灵异', '一家只在深夜开门的书屋，欢迎您的光临。——————');
insert into books (id, name, author, category, introduction) values (18, '道君', '跃千愁', '仙侠', '一个地球神级盗墓宗师，闯入修真界的故事……桃花源里，有歌声。山外青山，白骨山。五花马，千金裘，倚天剑。应我多情，啾啾鬼鸣，美人薄嗔。天地无垠，谁家旗鼓，碧落黄泉，万古高楼。为义气争');
insert into books (id, name, author, category, introduction) values (19, '牧神记', '宅猪', '玄幻', '大墟的祖训说，天黑，别出门。大墟残老村的老弱病残们从江边捡到了一个婴儿，取名秦牧，含辛茹苦将他养大。这一天夜幕降临，黑暗笼罩大墟，秦牧走出了家门……做个春风中荡漾的反派吧！瞎子对他');
insert into books (id, name, author, category, introduction) values (20, '儒道至圣', '永恒之火', '玄幻', '这是一个读书人掌握天地之力的世界。才气在身，诗可杀敌，词能灭军，文章安天下。秀才提笔，纸上谈兵；举人杀敌，出口成章；进士一怒，唇枪舌剑。圣人驾临，口诛笔伐，可诛人，可判天子无道，以');
insert into books (id, name, author, category, introduction) values (21, '飞剑问道', '我吃西红柿', '仙侠', '在这个世界，有狐仙、河神、水怪、大妖，也有求长生的修行者。修行者们，开法眼，可看妖魔鬼怪。炼一口飞剑，可千里杀敌。千里眼、顺风耳，更可探查四方。……秦府二公子‘秦云’，便是一位修行');
insert into books (id, name, author, category, introduction) values (22, '我是仙凡', '百里玺', '仙侠', '仙侠和种田结合。一名少年无意打开灵台，识海发现方寸灵山。从此种仙稻，养灵药，开洞府，开辟一片桃源仙境，踏上修仙之路。-------------------百里玺官方粉丝群：3328');
insert into books (id, name, author, category, introduction) values (23, '斗战狂潮', '骷髅精灵', '仙侠', '双月当空，无限可能的英魂世界孤寂黑暗，神秘古怪的嬉命小丑百城联邦，三大帝国，异族横行，魂兽霸幽这是一个英雄辈出的年代，人类卧薪尝胆重掌地球主权，孕育着进军高纬度的野望！重点是……二');
insert into books (id, name, author, category, introduction) values (24, '龙皇武神', '步征', '都市', '都市修仙至尊爽文！渡劫期大修士凌云魂穿都市，仙武同修，丹药、炼器，画符，布阵无所不能，以无敌之姿逆天崛起，脚踩八方！');
insert into books (id, name, author, category, introduction) values (25, '太初', '高楼大厦', '玄幻', '一树生的万朵花，天下道门是一家。法术千般变化，人心却亘古不变');
insert into books (id, name, author, category, introduction) values (26, '伏天氏', '净无痕', '玄幻', '东方神州，有人皇立道统，有圣贤宗门传道，有诸侯雄踞一方王国，诸强林立，神州动乱千万载，值此之时，一代天骄叶青帝及东凰大帝横空出世，斩人皇，驭圣贤，诸侯臣服，东方神州一统！然，叶青帝');
insert into books (id, name, author, category, introduction) values (27, '万界天尊', '血红', '玄幻', '天为何物？高高在上，威严莫测，是法则，是戒律，是无情，是冷酷。天意，何也？俯瞰众生，操持风云，褫夺赏罚，随性而为。故，天意不可测，苍天不可近。顺之应之，未必得其利；逆之叛之，福祸却');
insert into books (id, name, author, category, introduction) values (28, '苍穹之上', '石三', '仙侠', '苍穹之下的千年苦修，只为有朝一日立身于苍穹之上！位于洪武天朝和妖族七杀部咽喉要地的天断峡谷中，忽有天降神异之物，裹挟着一众修兵，滚入了浩荡的历史洪流当中……宋征只是其中不那么起眼的');
insert into books (id, name, author, category, introduction) values (29, '无疆', '小刀锋利', '仙侠', '鹰击长空，鱼跃龙门，熊咆虎啸，万物皆有灵。末法之极，磁极轮转，世界变迁。曾经那个熟悉的世界，已经变得面目全非。当神话变成现实，当传说不再神秘，世界无疆，热血永恒。');
insert into books (id, name, author, category, introduction) values (30, '圣墟', '辰东', '玄幻', '在破败中崛起，在寂灭中复苏。沧海成尘，雷电枯竭，那一缕幽雾又一次临近大地，世间的枷锁被打开了，一个全新的世界就此揭开神秘的一角……');
insert into books (id, name, author, category, introduction) values (31, '还看今朝', '瑞根', '都市', '当扑面而来的时代巨澜把懵懵懂懂的沙正阳卷入其中时，他是随波逐流，风花雪月，还是长缨在手，逆流击波？干想干的事，为恣意人生。做该做的事，为家国情怀。一万年太久，只争朝夕！到中流击水，');
insert into books (id, name, author, category, introduction) values (32, '凡人修仙之仙界篇', '忘语', '仙侠', '凡人修仙，风云再起时空穿梭，轮回逆转金仙太乙，大罗道祖三千大道，法则至尊《凡人修仙传》仙界篇，一个韩立叱咤仙界的故事，一个凡人小子修仙的不灭传说。特说明下，没有看过前传的书友，并不');
insert into books (id, name, author, category, introduction) values (33, '大王饶命', '会说话的肘子', '都市', '灵气复苏的时代，寂静生活碎掉了，仿佛雷霆贯穿长空，电光直射天心，雨沙沙地落下。凡逆我们的终将死去，这就是法则。……这是一个吕树依靠毒鸡汤成为大魔王的故事。');
insert into books (id, name, author, category, introduction) values (34, '汉乡', '孑与2', '历史', '我们接受了祖先的遗产，这让中华辉煌了数千年，我们是如此的心安理得，从未想过要回归那个在刀耕火种中苦苦寻找出路的时代。反哺我们苦难的祖先，并从中找到故乡的真正意义，将是本书要讲的故事');
insert into books (id, name, author, category, introduction) values (35, '修真聊天群', '圣骑士的传说', '都市', '某天，宋书航意外加入了一个仙侠中二病资深患者的交流群，里面的群友们都以‘道友’相称，群名片都是各种府主、洞主、真人、天师。连群主走失的宠物犬都称为大妖犬离家出走。整天聊的是炼丹、闯');
insert into books (id, name, author, category, introduction) values (36, '别玩网游', '尝谕', '都市', '新书请到这里。大家先收藏，新书发布时间待定。');
insert into books (id, name, author, category, introduction) values (37, '深夜书屋', '纯洁滴小龙', '灵异', '一家只在深夜开门的书屋，欢迎您的光临。——————');
insert into books (id, name, author, category, introduction) values (38, '道君', '跃千愁', '仙侠', '一个地球神级盗墓宗师，闯入修真界的故事……桃花源里，有歌声。山外青山，白骨山。五花马，千金裘，倚天剑。应我多情，啾啾鬼鸣，美人薄嗔。天地无垠，谁家旗鼓，碧落黄泉，万古高楼。为义气争');
insert into books (id, name, author, category, introduction) values (39, '牧神记', '宅猪', '玄幻', '大墟的祖训说，天黑，别出门。大墟残老村的老弱病残们从江边捡到了一个婴儿，取名秦牧，含辛茹苦将他养大。这一天夜幕降临，黑暗笼罩大墟，秦牧走出了家门……做个春风中荡漾的反派吧！瞎子对他');
insert into books (id, name, author, category, introduction) values (40, '儒道至圣', '永恒之火', '玄幻', '这是一个读书人掌握天地之力的世界。才气在身，诗可杀敌，词能灭军，文章安天下。秀才提笔，纸上谈兵；举人杀敌，出口成章；进士一怒，唇枪舌剑。圣人驾临，口诛笔伐，可诛人，可判天子无道，以');
insert into books (id, name, author, category, introduction) values (41, '飞剑问道', '我吃西红柿', '仙侠', '在这个世界，有狐仙、河神、水怪、大妖，也有求长生的修行者。修行者们，开法眼，可看妖魔鬼怪。炼一口飞剑，可千里杀敌。千里眼、顺风耳，更可探查四方。……秦府二公子‘秦云’，便是一位修行');
insert into books (id, name, author, category, introduction) values (42, '我是仙凡', '百里玺', '仙侠', '仙侠和种田结合。一名少年无意打开灵台，识海发现方寸灵山。从此种仙稻，养灵药，开洞府，开辟一片桃源仙境，踏上修仙之路。-------------------百里玺官方粉丝群：3328');
insert into books (id, name, author, category, introduction) values (43, '斗战狂潮', '骷髅精灵', '仙侠', '双月当空，无限可能的英魂世界孤寂黑暗，神秘古怪的嬉命小丑百城联邦，三大帝国，异族横行，魂兽霸幽这是一个英雄辈出的年代，人类卧薪尝胆重掌地球主权，孕育着进军高纬度的野望！重点是……二');
insert into books (id, name, author, category, introduction) values (44, '龙皇武神', '步征', '都市', '都市修仙至尊爽文！渡劫期大修士凌云魂穿都市，仙武同修，丹药、炼器，画符，布阵无所不能，以无敌之姿逆天崛起，脚踩八方！');
insert into books (id, name, author, category, introduction) values (45, '太初', '高楼大厦', '玄幻', '一树生的万朵花，天下道门是一家。法术千般变化，人心却亘古不变');
insert into books (id, name, author, category, introduction) values (46, '伏天氏', '净无痕', '玄幻', '东方神州，有人皇立道统，有圣贤宗门传道，有诸侯雄踞一方王国，诸强林立，神州动乱千万载，值此之时，一代天骄叶青帝及东凰大帝横空出世，斩人皇，驭圣贤，诸侯臣服，东方神州一统！然，叶青帝');
insert into books (id, name, author, category, introduction) values (47, '万界天尊', '血红', '玄幻', '天为何物？高高在上，威严莫测，是法则，是戒律，是无情，是冷酷。天意，何也？俯瞰众生，操持风云，褫夺赏罚，随性而为。故，天意不可测，苍天不可近。顺之应之，未必得其利；逆之叛之，福祸却');
insert into books (id, name, author, category, introduction) values (48, '苍穹之上', '石三', '仙侠', '苍穹之下的千年苦修，只为有朝一日立身于苍穹之上！位于洪武天朝和妖族七杀部咽喉要地的天断峡谷中，忽有天降神异之物，裹挟着一众修兵，滚入了浩荡的历史洪流当中……宋征只是其中不那么起眼的');
insert into books (id, name, author, category, introduction) values (49, '无疆', '小刀锋利', '仙侠', '鹰击长空，鱼跃龙门，熊咆虎啸，万物皆有灵。末法之极，磁极轮转，世界变迁。曾经那个熟悉的世界，已经变得面目全非。当神话变成现实，当传说不再神秘，世界无疆，热血永恒。');
insert into books (id, name, author, category, introduction) values (50, '圣墟', '辰东', '玄幻', '在破败中崛起，在寂灭中复苏。沧海成尘，雷电枯竭，那一缕幽雾又一次临近大地，世间的枷锁被打开了，一个全新的世界就此揭开神秘的一角……');
insert into books (id, name, author, category, introduction) values (51, '还看今朝', '瑞根', '都市', '当扑面而来的时代巨澜把懵懵懂懂的沙正阳卷入其中时，他是随波逐流，风花雪月，还是长缨在手，逆流击波？干想干的事，为恣意人生。做该做的事，为家国情怀。一万年太久，只争朝夕！到中流击水，');
insert into books (id, name, author, category, introduction) values (52, '凡人修仙之仙界篇', '忘语', '仙侠', '凡人修仙，风云再起时空穿梭，轮回逆转金仙太乙，大罗道祖三千大道，法则至尊《凡人修仙传》仙界篇，一个韩立叱咤仙界的故事，一个凡人小子修仙的不灭传说。特说明下，没有看过前传的书友，并不');
insert into books (id, name, author, category, introduction) values (53, '大王饶命', '会说话的肘子', '都市', '灵气复苏的时代，寂静生活碎掉了，仿佛雷霆贯穿长空，电光直射天心，雨沙沙地落下。凡逆我们的终将死去，这就是法则。……这是一个吕树依靠毒鸡汤成为大魔王的故事。');
insert into books (id, name, author, category, introduction) values (54, '汉乡', '孑与2', '历史', '我们接受了祖先的遗产，这让中华辉煌了数千年，我们是如此的心安理得，从未想过要回归那个在刀耕火种中苦苦寻找出路的时代。反哺我们苦难的祖先，并从中找到故乡的真正意义，将是本书要讲的故事');
insert into books (id, name, author, category, introduction) values (55, '修真聊天群', '圣骑士的传说', '都市', '某天，宋书航意外加入了一个仙侠中二病资深患者的交流群，里面的群友们都以‘道友’相称，群名片都是各种府主、洞主、真人、天师。连群主走失的宠物犬都称为大妖犬离家出走。整天聊的是炼丹、闯');
insert into books (id, name, author, category, introduction) values (56, '别玩网游', '尝谕', '都市', '新书请到这里。大家先收藏，新书发布时间待定。');
insert into books (id, name, author, category, introduction) values (57, '深夜书屋', '纯洁滴小龙', '灵异', '一家只在深夜开门的书屋，欢迎您的光临。——————');
insert into books (id, name, author, category, introduction) values (58, '道君', '跃千愁', '仙侠', '一个地球神级盗墓宗师，闯入修真界的故事……桃花源里，有歌声。山外青山，白骨山。五花马，千金裘，倚天剑。应我多情，啾啾鬼鸣，美人薄嗔。天地无垠，谁家旗鼓，碧落黄泉，万古高楼。为义气争');
insert into books (id, name, author, category, introduction) values (59, '牧神记', '宅猪', '玄幻', '大墟的祖训说，天黑，别出门。大墟残老村的老弱病残们从江边捡到了一个婴儿，取名秦牧，含辛茹苦将他养大。这一天夜幕降临，黑暗笼罩大墟，秦牧走出了家门……做个春风中荡漾的反派吧！瞎子对他');
insert into books (id, name, author, category, introduction) values (60, '儒道至圣', '永恒之火', '玄幻', '这是一个读书人掌握天地之力的世界。才气在身，诗可杀敌，词能灭军，文章安天下。秀才提笔，纸上谈兵；举人杀敌，出口成章；进士一怒，唇枪舌剑。圣人驾临，口诛笔伐，可诛人，可判天子无道，以');
insert into books (id, name, author, category, introduction) values (61, '飞剑问道', '我吃西红柿', '仙侠', '在这个世界，有狐仙、河神、水怪、大妖，也有求长生的修行者。修行者们，开法眼，可看妖魔鬼怪。炼一口飞剑，可千里杀敌。千里眼、顺风耳，更可探查四方。……秦府二公子‘秦云’，便是一位修行');
insert into books (id, name, author, category, introduction) values (62, '我是仙凡', '百里玺', '仙侠', '仙侠和种田结合。一名少年无意打开灵台，识海发现方寸灵山。从此种仙稻，养灵药，开洞府，开辟一片桃源仙境，踏上修仙之路。-------------------百里玺官方粉丝群：3328');
insert into books (id, name, author, category, introduction) values (63, '斗战狂潮', '骷髅精灵', '仙侠', '双月当空，无限可能的英魂世界孤寂黑暗，神秘古怪的嬉命小丑百城联邦，三大帝国，异族横行，魂兽霸幽这是一个英雄辈出的年代，人类卧薪尝胆重掌地球主权，孕育着进军高纬度的野望！重点是……二');
insert into books (id, name, author, category, introduction) values (64, '龙皇武神', '步征', '都市', '都市修仙至尊爽文！渡劫期大修士凌云魂穿都市，仙武同修，丹药、炼器，画符，布阵无所不能，以无敌之姿逆天崛起，脚踩八方！');
insert into books (id, name, author, category, introduction) values (65, '太初', '高楼大厦', '玄幻', '一树生的万朵花，天下道门是一家。法术千般变化，人心却亘古不变');
insert into books (id, name, author, category, introduction) values (66, '伏天氏', '净无痕', '玄幻', '东方神州，有人皇立道统，有圣贤宗门传道，有诸侯雄踞一方王国，诸强林立，神州动乱千万载，值此之时，一代天骄叶青帝及东凰大帝横空出世，斩人皇，驭圣贤，诸侯臣服，东方神州一统！然，叶青帝');
insert into books (id, name, author, category, introduction) values (67, '万界天尊', '血红', '玄幻', '天为何物？高高在上，威严莫测，是法则，是戒律，是无情，是冷酷。天意，何也？俯瞰众生，操持风云，褫夺赏罚，随性而为。故，天意不可测，苍天不可近。顺之应之，未必得其利；逆之叛之，福祸却');
insert into books (id, name, author, category, introduction) values (68, '苍穹之上', '石三', '仙侠', '苍穹之下的千年苦修，只为有朝一日立身于苍穹之上！位于洪武天朝和妖族七杀部咽喉要地的天断峡谷中，忽有天降神异之物，裹挟着一众修兵，滚入了浩荡的历史洪流当中……宋征只是其中不那么起眼的');
insert into books (id, name, author, category, introduction) values (69, '无疆', '小刀锋利', '仙侠', '鹰击长空，鱼跃龙门，熊咆虎啸，万物皆有灵。末法之极，磁极轮转，世界变迁。曾经那个熟悉的世界，已经变得面目全非。当神话变成现实，当传说不再神秘，世界无疆，热血永恒。');
insert into books (id, name, author, category, introduction) values (70, '圣墟', '辰东', '玄幻', '在破败中崛起，在寂灭中复苏。沧海成尘，雷电枯竭，那一缕幽雾又一次临近大地，世间的枷锁被打开了，一个全新的世界就此揭开神秘的一角……');
insert into books (id, name, author, category, introduction) values (71, '还看今朝', '瑞根', '都市', '当扑面而来的时代巨澜把懵懵懂懂的沙正阳卷入其中时，他是随波逐流，风花雪月，还是长缨在手，逆流击波？干想干的事，为恣意人生。做该做的事，为家国情怀。一万年太久，只争朝夕！到中流击水，');
insert into books (id, name, author, category, introduction) values (72, '凡人修仙之仙界篇', '忘语', '仙侠', '凡人修仙，风云再起时空穿梭，轮回逆转金仙太乙，大罗道祖三千大道，法则至尊《凡人修仙传》仙界篇，一个韩立叱咤仙界的故事，一个凡人小子修仙的不灭传说。特说明下，没有看过前传的书友，并不');
insert into books (id, name, author, category, introduction) values (73, '大王饶命', '会说话的肘子', '都市', '灵气复苏的时代，寂静生活碎掉了，仿佛雷霆贯穿长空，电光直射天心，雨沙沙地落下。凡逆我们的终将死去，这就是法则。……这是一个吕树依靠毒鸡汤成为大魔王的故事。');
insert into books (id, name, author, category, introduction) values (74, '汉乡', '孑与2', '历史', '我们接受了祖先的遗产，这让中华辉煌了数千年，我们是如此的心安理得，从未想过要回归那个在刀耕火种中苦苦寻找出路的时代。反哺我们苦难的祖先，并从中找到故乡的真正意义，将是本书要讲的故事');
insert into books (id, name, author, category, introduction) values (75, '修真聊天群', '圣骑士的传说', '都市', '某天，宋书航意外加入了一个仙侠中二病资深患者的交流群，里面的群友们都以‘道友’相称，群名片都是各种府主、洞主、真人、天师。连群主走失的宠物犬都称为大妖犬离家出走。整天聊的是炼丹、闯');
insert into books (id, name, author, category, introduction) values (76, '别玩网游', '尝谕', '都市', '新书请到这里。大家先收藏，新书发布时间待定。');
insert into books (id, name, author, category, introduction) values (77, '深夜书屋', '纯洁滴小龙', '灵异', '一家只在深夜开门的书屋，欢迎您的光临。——————');
insert into books (id, name, author, category, introduction) values (78, '道君', '跃千愁', '仙侠', '一个地球神级盗墓宗师，闯入修真界的故事……桃花源里，有歌声。山外青山，白骨山。五花马，千金裘，倚天剑。应我多情，啾啾鬼鸣，美人薄嗔。天地无垠，谁家旗鼓，碧落黄泉，万古高楼。为义气争');
insert into books (id, name, author, category, introduction) values (79, '牧神记', '宅猪', '玄幻', '大墟的祖训说，天黑，别出门。大墟残老村的老弱病残们从江边捡到了一个婴儿，取名秦牧，含辛茹苦将他养大。这一天夜幕降临，黑暗笼罩大墟，秦牧走出了家门……做个春风中荡漾的反派吧！瞎子对他');
insert into books (id, name, author, category, introduction) values (80, '儒道至圣', '永恒之火', '玄幻', '这是一个读书人掌握天地之力的世界。才气在身，诗可杀敌，词能灭军，文章安天下。秀才提笔，纸上谈兵；举人杀敌，出口成章；进士一怒，唇枪舌剑。圣人驾临，口诛笔伐，可诛人，可判天子无道，以');
insert into books (id, name, author, category, introduction) values (81, '飞剑问道', '我吃西红柿', '仙侠', '在这个世界，有狐仙、河神、水怪、大妖，也有求长生的修行者。修行者们，开法眼，可看妖魔鬼怪。炼一口飞剑，可千里杀敌。千里眼、顺风耳，更可探查四方。……秦府二公子‘秦云’，便是一位修行');
insert into books (id, name, author, category, introduction) values (82, '我是仙凡', '百里玺', '仙侠', '仙侠和种田结合。一名少年无意打开灵台，识海发现方寸灵山。从此种仙稻，养灵药，开洞府，开辟一片桃源仙境，踏上修仙之路。-------------------百里玺官方粉丝群：3328');
insert into books (id, name, author, category, introduction) values (83, '斗战狂潮', '骷髅精灵', '仙侠', '双月当空，无限可能的英魂世界孤寂黑暗，神秘古怪的嬉命小丑百城联邦，三大帝国，异族横行，魂兽霸幽这是一个英雄辈出的年代，人类卧薪尝胆重掌地球主权，孕育着进军高纬度的野望！重点是……二');
insert into books (id, name, author, category, introduction) values (84, '龙皇武神', '步征', '都市', '都市修仙至尊爽文！渡劫期大修士凌云魂穿都市，仙武同修，丹药、炼器，画符，布阵无所不能，以无敌之姿逆天崛起，脚踩八方！');
insert into books (id, name, author, category, introduction) values (85, '太初', '高楼大厦', '玄幻', '一树生的万朵花，天下道门是一家。法术千般变化，人心却亘古不变');
insert into books (id, name, author, category, introduction) values (86, '伏天氏', '净无痕', '玄幻', '东方神州，有人皇立道统，有圣贤宗门传道，有诸侯雄踞一方王国，诸强林立，神州动乱千万载，值此之时，一代天骄叶青帝及东凰大帝横空出世，斩人皇，驭圣贤，诸侯臣服，东方神州一统！然，叶青帝');
insert into books (id, name, author, category, introduction) values (87, '万界天尊', '血红', '玄幻', '天为何物？高高在上，威严莫测，是法则，是戒律，是无情，是冷酷。天意，何也？俯瞰众生，操持风云，褫夺赏罚，随性而为。故，天意不可测，苍天不可近。顺之应之，未必得其利；逆之叛之，福祸却');
insert into books (id, name, author, category, introduction) values (88, '苍穹之上', '石三', '仙侠', '苍穹之下的千年苦修，只为有朝一日立身于苍穹之上！位于洪武天朝和妖族七杀部咽喉要地的天断峡谷中，忽有天降神异之物，裹挟着一众修兵，滚入了浩荡的历史洪流当中……宋征只是其中不那么起眼的');
insert into books (id, name, author, category, introduction) values (89, '无疆', '小刀锋利', '仙侠', '鹰击长空，鱼跃龙门，熊咆虎啸，万物皆有灵。末法之极，磁极轮转，世界变迁。曾经那个熟悉的世界，已经变得面目全非。当神话变成现实，当传说不再神秘，世界无疆，热血永恒。');
insert into books (id, name, author, category, introduction) values (90, '圣墟', '辰东', '玄幻', '在破败中崛起，在寂灭中复苏。沧海成尘，雷电枯竭，那一缕幽雾又一次临近大地，世间的枷锁被打开了，一个全新的世界就此揭开神秘的一角……');
insert into books (id, name, author, category, introduction) values (91, '还看今朝', '瑞根', '都市', '当扑面而来的时代巨澜把懵懵懂懂的沙正阳卷入其中时，他是随波逐流，风花雪月，还是长缨在手，逆流击波？干想干的事，为恣意人生。做该做的事，为家国情怀。一万年太久，只争朝夕！到中流击水，');
insert into books (id, name, author, category, introduction) values (92, '凡人修仙之仙界篇', '忘语', '仙侠', '凡人修仙，风云再起时空穿梭，轮回逆转金仙太乙，大罗道祖三千大道，法则至尊《凡人修仙传》仙界篇，一个韩立叱咤仙界的故事，一个凡人小子修仙的不灭传说。特说明下，没有看过前传的书友，并不');
insert into books (id, name, author, category, introduction) values (93, '大王饶命', '会说话的肘子', '都市', '灵气复苏的时代，寂静生活碎掉了，仿佛雷霆贯穿长空，电光直射天心，雨沙沙地落下。凡逆我们的终将死去，这就是法则。……这是一个吕树依靠毒鸡汤成为大魔王的故事。');
insert into books (id, name, author, category, introduction) values (94, '汉乡', '孑与2', '历史', '我们接受了祖先的遗产，这让中华辉煌了数千年，我们是如此的心安理得，从未想过要回归那个在刀耕火种中苦苦寻找出路的时代。反哺我们苦难的祖先，并从中找到故乡的真正意义，将是本书要讲的故事');
insert into books (id, name, author, category, introduction) values (95, '修真聊天群', '圣骑士的传说', '都市', '某天，宋书航意外加入了一个仙侠中二病资深患者的交流群，里面的群友们都以‘道友’相称，群名片都是各种府主、洞主、真人、天师。连群主走失的宠物犬都称为大妖犬离家出走。整天聊的是炼丹、闯');
insert into books (id, name, author, category, introduction) values (96, '别玩网游', '尝谕', '都市', '新书请到这里。大家先收藏，新书发布时间待定。');
insert into books (id, name, author, category, introduction) values (97, '深夜书屋', '纯洁滴小龙', '灵异', '一家只在深夜开门的书屋，欢迎您的光临。——————');
insert into books (id, name, author, category, introduction) values (98, '道君', '跃千愁', '仙侠', '一个地球神级盗墓宗师，闯入修真界的故事……桃花源里，有歌声。山外青山，白骨山。五花马，千金裘，倚天剑。应我多情，啾啾鬼鸣，美人薄嗔。天地无垠，谁家旗鼓，碧落黄泉，万古高楼。为义气争');
insert into books (id, name, author, category, introduction) values (99, '牧神记', '宅猪', '玄幻', '大墟的祖训说，天黑，别出门。大墟残老村的老弱病残们从江边捡到了一个婴儿，取名秦牧，含辛茹苦将他养大。这一天夜幕降临，黑暗笼罩大墟，秦牧走出了家门……做个春风中荡漾的反派吧！瞎子对他');
insert into books (id, name, author, category, introduction) values (100, '儒道至圣', '永恒之火', '玄幻', '这是一个读书人掌握天地之力的世界。才气在身，诗可杀敌，词能灭军，文章安天下。秀才提笔，纸上谈兵；举人杀敌，出口成章；进士一怒，唇枪舌剑。圣人驾临，口诛笔伐，可诛人，可判天子无道，以');
