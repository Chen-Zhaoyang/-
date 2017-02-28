<div id = "main">
	<div class = "container">
		<div class = "bottom_title">
			<a class = "usual_button" href = "admin.php">基本</a>
			<a class = "usual_button" href = "user.php">用户</a>
			<a class = "usual_button" href = "role.php">角色</a>
			<a class = "usual_button" href = "renewal.php">续期</a>
			<a class = "usual_button" href = "update.php">更新</a>
		</div>
		<?php if (!DataUtil::is_exits("do")) { ?>
		<table border = "0" cellpadding = "0" cellspacing = "0">
			<tr class="odd_tr">
				<td class = "td_left">当前版本号</td>
				<td class = "td_right"><code><?php echo VERSION; ?></code></td>
			</tr>
			<tr>
				<td class = "td_left">最新版本号</td>
				<td class = "td_right"><code><?php echo $new_version; ?></code></td>
			</tr>
			<tr class = "odd_tr">
				<td colspan="2">
					<input type = "button" class="white_button" onclick="javascript:window.location.href='update.php?do=log'" value = "更新日志" />
					<?php if ($is_continue) { ?>
					<input type = "button" class="white_button" onclick="javascript:window.location.href='update.php?do=explain'" value = "更新详情" />
					<?php }  else { ?>
					<input type = "button" class="disable_button" value = "暂无更新" disabled="disabled" />
					<?php } ?>
				</td>
			</tr>
		</table>
		<?php } elseif ($do == "log") {?>
		<table border = "0" cellpadding = "0" cellspacing = "0">
			<tr class="odd_tr">
				<td>更新版本</td>
				<td>更新日志</td>
				<td>更新时间</td>
			</tr>
			<?php if ($logs) { ?>
			<?php $index = 0;?>
			<?php foreach ($logs as $log) { $index++;?>
			<tr <?php echo $index % 2 == 0 ? "class=\"odd_tr\"":"";?>>
				<td><?php echo $log['version'];?></td>
				<td><?php echo htmlspecialchars($log['plain']);?></td>
				<td><?php echo date('Y-m-d H:i:s', $log['createdate']);?></td>
			</tr>
			<?php } ?>
			<?php } else { ?>
			<tr><td colspan="3">暂无日志</td></tr>
			<?php } ?>
		</table>
		<div class = "paging">
			<a href = "update.php?do=log&pageno=1"><i class = "fa fa-arrow-left fa-fw"></i></a>
			<a href = "update.php?do=log&pageno=<?php echo $pageno - 1;?>"><i class = "fa fa-angle-double-left fa-fw"></i></a>
			<a href = "update.php?do=log&pageno=<?php echo $pageno + 1;?>"><i class = "fa fa-angle-double-right fa-fw"></i></a>
			<a href = "update.php?do=log&pageno=<?php echo $total;?>"><i class = "fa fa-arrow-right fa-fw"></i></a>
			<input type = "text" id = "pageno_down" value = "<?php echo $pageno; ?>" />
			<input type = "button" value = "跳页" onclick = "gopage('pageno_down')" />
		</div>
		<?php } else { ?>
		<table border = "0" cellpadding = "0" cellspacing = "0">
			<tr class="odd_tr">
				<td class = "td_left">更新文件</td>
				<td class = "td_right">
					<?php foreach ($fileArray as $file) { ?>
					<p><?php echo $file['name']; ?><br/><?php echo $file['is_writable'] ? "<span class = \"tip-green\">可写<i class = \"fa fa-check fa-fw\"></i></span>" : "<span class = \"tip-red\">不可写<i class = \"fa fa-times fa-fw\"></i></span>";?></p>
					<?php } ?>
				</td>
			</tr>
			<tr>
				<td class = "td_left">执行SQL</td>
				<td class = "td_right">
					<?php foreach ($sqlArray as $sql) { ?>
					<p><?php echo $sql; ?></p>
					<?php } ?>
				</td>
			</tr>
			<tr class = "odd_tr">
				<td class = "td_left">更新说明</td>
				<td class = "td_right">
					<?php foreach ($plainArray as $plain) { ?>
					<p><?php echo $plain; ?></p>
					<?php } ?>
				</td>
			</tr>
			<tr>
				<td colspan="2">
					<?php if ($is_continue) { ?>
					<input type = "button" class="white_button" onclick="javascript:window.location.href='update.php?do=update'" value = "立即更新" />
					<?php }  else { ?>
					<input type = "button" class="disable_button" value = "无法更新" disabled="disabled" />
					<?php } ?>
				</td>
			</tr>
		</table>
		<?php } ?>
	</div>
</div>
<script type = "text/javascript">
function gopage(id) {
	var pageno = document.getElementById(id).value;
	window.location.href = "update.php?do=log&pageno=" + pageno; 
}
</script>