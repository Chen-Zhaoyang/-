<div id = "main">
	<div class = "container">
		<form id = "loginForm" action = "runqq.php" method = "post">
			<input type = "hidden" name = "rsa_pass" id = "rsa_pass" />
			<input type = "hidden" id = "code" value = "<?php echo $robot['code']; ?>" />
			<input type = "hidden" id = "uin" name = "uin" value = "<?php echo $robot['uin'];?>" />
			<ul class = "form_ul">
				<li><span class = "form_span"><?php echo $robot['is_run'] == 0 ? "<font color = \"red\">未开启</font>" : ("<font color = \"green\">已开启-</font>" . $statusDes); ?></span></li>
				<li><label class = "form_label" for = "uin"><i class = "fa fa-qq fa-fw"></i></label><span class = "form_p_title">ＱＱ账号 | <span class = "tip-color1"><?php echo $robot['uin'];?></span></span></li>
				<li><label class = "form_label" for = "uin"><i class = "fa fa-calendar fa-fw"></i></label><span class = "form_p_title">使用期限 | <span class = "tip-color7"><?php echo date('Y-m-d H:i', $robot['limitdate']);?></span></span></li>
				<li><label class = "form_label" for = "uin"><i class = "fa fa-cny fa-fw"></i></label><span class = "form_p_title">金币续期 | <a href = "renqq.php?robot_id=<?php echo $robot['id'];?>">续期机器人</a></span></li>
			</ul>
			<?php if ($robot['is_run'] == 1 && $robot['status'] == StatusUtil::LOADING_VERIFY) { ?>
			<a class="ewm" href = "img.php?robot_id=<?php echo $robot['id']; ?>" target = "_blank" title = "新窗口打开验证码"><img src = "img.php?robot_id=<?php echo $robot['id']; ?>" /></a>
			<?php } ?>
		</form>
		<ul class = "ul_none">
		<?php if ($logs) { ?>
		<?php foreach ($logs as $log) { ?>
		<li title="<?php echo htmlspecialchars($log['msg']);?>">
			<i class = "fa fa-music fa-fw tip-color<?php echo rand(1, 7);?>"></i><?php echo htmlspecialchars($log['msg']); ?>
			<i class = "fa fa-clock-o fa-fw"></i><?php echo date('Y-m-d H:i:s', $log['createdate']);?>
		</li>
		<?php } ?>
		<?php } else { ?>
		<li><i class = "fa fa-music fa-fw tip-color<?php echo rand(1, 7);?>"></i>暂无执行记录<i class = "fa fa-clock-o fa-fw"></i><?php echo date('Y-m-d H:i:s', time());?></li>
		<?php } ?>
		</ul>
		<div class = "paging center_auto">
			<a href = "runqq.php?uin=<?php echo $robot['uin'];?>&pageno=1"><i class = "fa fa-arrow-left fa-fw"></i></a>
			<a href = "runqq.php?uin=<?php echo $robot['uin'];?>&pageno=<?php echo $pageno - 1;?>"><i class = "fa fa-angle-double-left fa-fw"></i></a>
			<a href = "runqq.php?uin=<?php echo $robot['uin'];?>&pageno=<?php echo $pageno + 1;?>"><i class = "fa fa-angle-double-right fa-fw"></i></a>
			<a href = "runqq.php?uin=<?php echo $robot['uin'];?>&pageno=<?php echo $total;?>"><i class = "fa fa-arrow-right fa-fw"></i></a>
			<input type = "text" id = "pageno_down" value = "<?php echo $pageno; ?>" />
			<input type = "button" value = "跳页" onclick = "gopage('pageno_down')" />
		</div>
	</div>
</div>

<script type = "text/javascript">
function gopage(id) {
	var pageno = document.getElementById(id).value;
	window.location.href = "runqq.php?uin=<?php echo $robot['uin'];?>&pageno=" + pageno; 
}
</script>