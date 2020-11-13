class bankAccount
{
    private:
      std::string firstName;
      std::string lastName;
      int account;
      short pin;
      float balance;

    public:
      bankAccount();
      bankAccount(std::string firstName,std::string lastName, int account, short pin, float balance); //constructor
      ~bankAccount(); 
      int getAccountNumber() const;
      bool operator<(const bankAccount &) const;
      void display() const;
};
