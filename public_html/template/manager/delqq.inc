<div id = "main">
	<div class = "container">
		<form action = "" method = "post">
			<?php if (isset($delResult)) { ?>
			<div class = "form_title"><span class = "tip-red">删除失败</span></div>
			<?php } ?>
			<input type = "hidden" name = "del_uin" value = "<?php echo DataUtil::param_mysql_filter("uin"); ?>" />
			<ul class = "form_ul">
				<li><label class = "form_label" for = "uin"><i class = "fa fa-qq fa-fw"></i></label><span class = "form_p_title">ＱＱ账号 | <span class = "tip-color1"><?php echo $robot['uin'];?></span></span></li>
				<li><label class = "form_label" for = "uin"><i class = "fa fa-calendar fa-fw"></i></label><span class = "form_p_title">使用期限 | <span class = "tip-color7"><?php echo date('Y-m-d H:i', $robot['limitdate']);?></span></span></li>
				<li><input class = "form_button" type = "submit" value = "确认删除" /></li>
			</ul>
		</form>
	</div>
</div>