<?php if (!defined('ITPK')) exit('You can not directly access the file.');

/**
 * Webqq数据库连接类
 * @author 冬天的秘密
 * @link http://bbs.itpk.cn
 * @version 1.0
 */

class UpdateSql extends BaseSql {

	public function __construct($table) {
		$this->table = $table;
		$this->setUpdateTable();
	}

	public function executeUpdateSql($db) {
		return $db->executeQuery($this->getSqlStr()) > 0 ? true : false;
	}

}

?>