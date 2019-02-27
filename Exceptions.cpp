/*! \brief Class specific for throwing exception for dependency errors
 *         
 *
 *  The dependency exception class should take a construction parameter of the
 *  shell program which has been found by the program to not be available, then
 *  display a message detailing exception not found
 * 
 */
struct DependencyException : public std::exception {
  const char* dep;
  DependencyException (const char* dep_) : dep(dep_)
  {
    std::cout << "WARNING: Crucial dependency not found. Please resolve the following dependencies:" << std::endl;
  }
  /*
    ...
    /// Returns value of dependency not met
    /// @param n/a
    /// @return dependency as defined in the constructor of the class
    ...
  */

  const char * what () const throw () {
    return dep;
  }
};
/*! \brief Class specific for throwing exception for bad argument errors
 *         
 *
 *  The argument exception class should take a construction parameter of the
 *  message to be displayed detailing the issues of arguments not being met.
 *  
 * 
 */

struct ArgException : public std::exception {
  const char* _msg;
  ArgException (const char* msg) : _msg(msg) {}
  /*
    ...
    /// MSG as defined in constructor
    /// @param n/a
    /// @return Msg given by the constructor
    ...
  */

  virtual const char* what() const noexcept override{
    return _msg;
  }

};
