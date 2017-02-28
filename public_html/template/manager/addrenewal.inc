<div id = "main">
	<div class = "container">
		<?php if (isset($saveResult)) { ?>
		<div class = "form_title"><span class = "tip-red"><?php echo $saveResult ? "添加成功" : "添加失败"; ?></span></div>
		<?php } ?>
		<div class = "bottom_title">
			<a class = "usual_button" href = "admin.php">基本</a>
			<a class = "usual_button" href = "user.php">用户</a>
			<a class = "usual_button" href = "role.php">角色</a>
			<a class = "usual_button" href = "renewal.php">续期</a>
			<a class = "usual_button" href = "update.php">更新</a>
		</div>
		<form action = "addrenewal.php" method = "post">
			<input type = "hidden" name = "save" value = "true" />
			<table border = "0" cellpadding = "0" cellspacing = "0">
				<tr class = "odd_tr">
					<td class = "td_left">配置名</td>
					<td class = "td_right"><input type = "text" name = "name" /></td>
				</tr>
				<tr>
					<td class = "td_left">排序</td>
					<td class = "td_right"><input type = "text" name = "sort" /></td>
				</tr>
				<tr class = "odd_tr">
					<td class = "td_left">续期天数</td>
					<td class = "td_right"><input type = "text" name = "day_time" /></td>
				</tr>
				<tr>
					<td class = "td_left">购买金币</td>
					<td class = "td_right"><input type = "text" name = "gold" /></td>
				</tr>
				<tr class = "odd_tr">
					<td colspan="2"><input type = "submit" class="white_button" value = "确认添加" /></td>
				</tr>
			</table>
		</form>
	</div>
</div>