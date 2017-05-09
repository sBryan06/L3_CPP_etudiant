class Plot {
public:
  // TODO
  virtual void plot() = 0;
};

class Trips : public Plot{
};

class Brands : public Plot{
};

class Calls : public Plot{
};

class Drivers : public Plot{
};

class Gps : public Plot{
};
