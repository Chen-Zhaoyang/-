<div id = "main">
	<div class = "container">
		<div class = "bottom_title">
			<a class = "usual_button" href = "exchange.php">兑换卡号</a>
			<a class = "usual_button" href = "exchange.php?do=buy">购买卡号</a>
			<a class = "usual_button" href = "exchange.php?do=log">兑换记录</a>
		</div>
		<form action = "exchange.php" method = "post">
			<ul class = "form_ul">
				<li title = "卡号"><label class = "form_label" for = "card_number"><i class = "fa fa-gg fa-fw"></i></label><input class = "form_input" type = "text" id = "card_number" name = "card_number" placeholder = "请输入卡号" /></li>
				<li><input class = "form_button" type = "submit" value = "确认兑换" /></li>
			</ul>
		</form>
	</div>
</div>