<?php if (!defined('ITPK')) exit('You can not directly access the file.');

/**
 * Webqq数据库连接类
 * @author 冬天的秘密
 * @link http://bbs.itpk.cn
 * @version 1.0
 */

class BaseSql {

	protected $sql;
	protected $table;

	protected function setSelectTable($columns = "*") {
		$this->sql = "SELECT " . $columns . " FROM " . $this->table;
	}

	protected function setDeleteTable() {
		$this->sql = "DELETE FROM " . $this->table;
	}

	protected function setUpdateTable() {
		$this->sql = "UPDATE " . $this->table;
	}

	public function setUpdateValue($column, $columnValue) {
		if (!DataUtil::is_contain("SET", $this->sql)) {
			$this->sql .= " SET ";
		} else {
			$this->sql .= ", ";
		}
		if (!is_numeric($columnValue)) {
			$columnValue = "'" . $columnValue . "'";
		}
		$this->sql .= ($column . " = " . $columnValue);
	}

	public function setUpdateSelfValue($column, $columnValue, $symbol = "+") {
		if (!DataUtil::is_contain("SET", $this->sql)) {
			$this->sql .= " SET ";
		} else {
			$this->sql .= ", ";
		}
		if (!is_numeric($columnValue)) {
			$columnValue = "'" . $columnValue . "'";
		}
		$this->sql .= ($column . " = " . $column . " " . $symbol . " " . $columnValue);
	}

	private function setInsertOrReplace($columnArray, $columnValueArray, $is_insert = true) {
		$this->sql = ($is_insert ? "INSERT" : "REPLACE") . " INTO " . $this->table;
		$columnSql = "";
		for ($i = 0; $i < count($columnArray); $i++) {
			if ($columnSql != "") {
				$columnSql .= ", ";
			}
			$columnSql .= $columnArray[$i];
		}
		$columnValueSql = "";
		for ($i = 0; $i < count($columnValueArray); $i++) {
			if ($columnValueSql != "") {
				$columnValueSql .= ", ";
			}
			if (is_numeric($columnValueArray[$i])) {
				$columnValueSql .= $columnValueArray[$i];
			} else {
				$columnValueSql .= ("'" . $columnValueArray[$i] . "'");
			}
		}
		$this->sql .= " (" . $columnSql . ") VALUES (" . $columnValueSql . ")";
	}

	public function setInsert($columnArray, $columnValueArray) {
		$this->setInsertOrReplace($columnArray, $columnValueArray, true);
	}

	public function setReplace($columnArray, $columnValueArray) {
		$this->setInsertOrReplace($columnArray, $columnValueArray, false);
	}

	private function setWhereForAndOr($column, $columnValue, $term = "=", $is_and = true) {
		if (!DataUtil::is_contain("WHERE", $this->sql)) {
			$this->sql .= " WHERE ";
		} else {
			$this->sql .= ($is_and ? " AND " : " OR ");
		}
		if (!is_numeric($columnValue)) {
			$columnValue = "'" . $columnValue . "'";
		}
		$this->sql .= ($column . " " . $term . " (" . $columnValue . ")");
	}

	public function setWhere($column, $columnValue, $term = "=") {
		$this->setWhereForAndOr($column, $columnValue, $term, true);
	}

	public function setWhereOr($column, $columnValue, $term = "=") {
		$this->setWhereForAndOr($column, $columnValue, $term, false);
	}

	public function setOrder($order, $is_asc = "ASC") {
		$this->sql .= " ORDER BY " . $order . " " . $is_asc;
	}

	public function setLimitAndOffset($limit = 1, $offset = 0) {
		$this->sql .= " LIMIT " . $limit . " OFFSET " . $offset;
	}

	public function getSqlStr() {
		return $this->sql;
	}

}

?>