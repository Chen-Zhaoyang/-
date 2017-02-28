<?php 

/**
 * 公共头部文件
 * @author 冬天的秘密
 * @link http://bbs.itpk.cn
 * @version 1.0
 */

global $_set_html_title;
global $_link_file_array;
global $styleDef;

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="description" content="茉莉机器人官网，出生于2014年的新型机器人，广泛应用于各类网站客服、QQ机器人和微信公众平台。" />
<meta name="keywords" content="机器人,网页机器人,机器人api,机器人接口,茉莉机器人,QQ机器人,微信机器人" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width,initial-scale=1.0,minimum-scale=1.0,maximum-scale=1.0" />
<title><?php echo $_set_html_title . " - " . DOMAIN_NAME; ?></title>

<link rel="stylesheet" href="<?php echo DOMAIN_FOLDER . CSS_FOLDER; ?>animation.css" />
<link rel="stylesheet" href="http://apps.bdimg.com/libs/fontawesome/4.4.0/css/font-awesome.min.css" />
<link rel = "stylesheet" href = "<?php echo DOMAIN_FOLDER . CSS_FOLDER . $styleDef; ?>?ver=<?php echo VERSION;?>" type = "text/css" media = "all" />
<?php if (isset($_link_file_array)) { ?>
<?php foreach ($_link_file_array as $link_file) { ?>
<link rel = "stylesheet" href = "<?php echo DOMAIN_FOLDER . CSS_FOLDER . $link_file; ?>?ver=<?php echo VERSION;?>" type = "text/css" media = "all" />
<?php } ?>
<?php } ?>
</head>

<body>
<div id = "header">
	<div class = "container">
		<div class="navbar_sub">
			<?php echo $_set_html_title; ?>
			<a class="navbar_menu navbar_menu_home" href="<?php echo DOMAIN_FOLDER; ?>" title="首页"><i class="fa fa-home fa-fw"></i></a>
			<a class="navbar_menu navbar_menu_robot" href="<?php echo DOMAIN_FOLDER; ?>robot.php" title="机器人"><i class="fa fa-user-secret fa-fw"></i></a>
			<?php if (LOGIN_STATUS == UserLoginUtil::SUCCESS) { ?>
			<a class="navbar_menu navbar_menu_user" href = "profile.php" title="个人中心"><i class="fa fa-television fa-fw"></i></a>
			<?php } else { ?>
			<a class="navbar_menu navbar_menu_user" href = "login.php" title="登录"><i class="fa fa-sign-in fa-fw"></i></a>
			<?php } ?>
			<span class="navbar_menu navbar_menu_bars" id="barshook" title="菜单"><i class="fa fa-bars fa-fw"></i></span>
		</div>
		<ul id = "navbar" class = "navbar">
			<li class="navto-robot">
				<a href = "<?php echo DOMAIN_FOLDER; ?>robot.php"><i class="fa fa-user-secret fa-fw"></i>机器人</a>
			</li>
			<li class="navto-chat">
				<a href = "<?php echo DOMAIN_FOLDER; ?>chat.php"><i class="fa fa-commenting fa-fw"></i>聊天室</a>
			</li>
			<li class="navto-user">
				<a href = "<?php echo DOMAIN_FOLDER; ?>admin.php"><i class="fa fa-tachometer fa-fw"></i>后台管理</a>
			</li>
			<li class="navto-plugin">
				<a href = "<?php echo DOMAIN_FOLDER; ?>plugin.php"><i class="fa fa-tags fa-fw"></i>插件中心</a>
			</li>
			<li class="navto-exchange">
				<a href = "<?php echo DOMAIN_FOLDER; ?>exchange.php"><i class="fa fa-diamond fa-fw"></i>兑换中心</a>
			</li>
		</ul>
	</div>
</div>