
class EmployeeDAO {
public:
  // 当更换数据库时(MySQL、SQLServer、Oracle)，这些带有new的语句都要进行变化
  vector<EmployeeDO> GetEmployees() {
    SqlConnection* connection = new SqlConnection();
    connection->ConnectionString = "...";

    SqlCommand* command = new SqlCommand();
    command->CommandText = "...";
    command->SetConnection(connection);

    SqlDataReader* reader = command->ExecuteReader();
    while (reader->Read()) {
    }
  }
};
