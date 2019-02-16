//Exception for throwing when dependencies are not met
struct DependencyException : public std::exception {
  const char* dep;
  DependencyException (const char* dep_) : dep(dep_)
  {
    std::cout << "WARNING: Crucial dependency not found. Please resolve the following dependencies:" << std::endl;
  }
  const char * what () const throw () {
    return dep;
  }
};

struct ArgException : public std::exception {
  const char* _msg;
  ArgException (const char* msg) : _msg(msg) {}

  virtual const char* what() const noexcept override{
    return _msg;
  }

};
