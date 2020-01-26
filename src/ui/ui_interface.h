#ifndef RMBR_UI_UI_INTERFACE_H_
#define RMBR_UI_UI_INTERFACE_H_

namespace rmbr {

// TODO: Singleton?
class UiInterface {
 public:
  virtual bool Start() = 0;

 private:
};

}  // namespace rmbr
#endif  // RMBR_UI_UI_INTERFACE_H_