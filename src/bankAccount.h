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
      void display() const;
};