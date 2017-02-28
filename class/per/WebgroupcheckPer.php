<?php if (!defined('ITPK')) exit('You can not directly access the file.');

/**
 * 群检测操作类
 * @author 冬天的秘密
 * @link http://bbs.itpk.cn
 * @version 1.0
 */

class WebgroupcheckPer extends WebDBConnection {
	
	private $table = "web_group_check";

	/**
	 * 根据群代码获取群检测记录
	 * @param int $group_code
	 * @return array
	 */
	public function getMeByGroupCode($group_code) {
		$selectSql = new SelectSql($this->table);
		$selectSql->setWhere("group_code", $group_code);
		$selectSql->setLimitAndOffset(1, 0);
		return $selectSql->executeSelectSql($this->db);
	}

	/**
	 * 更新或添加群检测记录
	 * @param int $robot_id
	 * @param int $group_code
	 * @param int $group_uin
	 * @return boolean
	 */
	public function replaceMe($robot_id, $group_code, $group_uin) {
		$replaceSql = new ReplaceSql($this->table);
		$replaceSql->setReplace(array("robot_id", "group_code", "group_uin"), array($robot_id, $group_code, $group_uin));
		return $replaceSql->executeReplaceSql($this->db);
	}

} 
?>