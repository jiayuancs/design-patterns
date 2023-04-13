// 使用Factory Method进行重构

// 数据库访问有关的基类
class IDBConnection {};
class IDBConnectionFactory {
public:
  virtual IDBConnection* CreateDBConnection() = 0;
};

class IDBCommand {};
class IDBCommandFactory {
public:
  virtual IDBCommand* CreateDBCommand() = 0;
};

class IDataReader {};
class IDataReaderFactory {
public:
  virtual IDataReader* CreateDataReader() = 0;
};

// 支持SQL Server
class SqlConnection : public IDBConnection {};
class SqlConnectionFactory : public IDBConnectionFactory {};

class SqlCommand : public IDBCommand {};
class SqlCommandFactory : public IDBCommandFactory {};

class SqlDataReader : public IDataReader {};
class SqlDataReaderFactory : public IDataReaderFactory {};

// 支持Oracle
class OracleConnection : public IDBConnection {};

class OracleCommand : public IDBCommand {};

class OracleDataReader : public IDataReader {};

class EmployeeDAO {
  // 存在的问题：这三个对象之间是有关联的，
  // 即我们不能将一个SQLServer的Connect与一个MySQL的Command进行搭配
  IDBConnectionFactory* dbConnectionFactory;
  IDBCommandFactory* dbCommandFactory;
  IDataReaderFactory* dataReaderFactory;

public:
  vector<EmployeeDO> GetEmployees() {
    IDBConnection* connection = dbConnectionFactory->CreateDBConnection();
    connection->ConnectionString("...");

    IDBCommand* command = dbCommandFactory->CreateDBCommand();
    command->CommandText("...");
    command->SetConnection(connection);  // 关联性

    IDataReader* reader = command->ExecuteReader();  // 关联性
    while (reader->Read()) {
    }
  }
};
