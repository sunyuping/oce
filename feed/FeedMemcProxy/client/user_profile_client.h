
#ifndef _XCE_USER_PROFILE_CLIENT_H_
#define _XCE_USER_PROFILE_CLIENT_H_

#include <Ice/Ice.h>

#include "MemcachedClientPool.h"
#include "Singleton.h"
#include "user_profile.pb.h"

namespace xce {
namespace ad {

using namespace MyUtil;

class UserProfileClient : public Singleton<UserProfileClient> {
public:
  UserProfileClient();
  ~UserProfileClient();

  bool Get(Ice::Int uid, UserProfile * profile);
  bool Set(const UserProfile & o);
  bool GetSerialized(Ice::Int uid, string * serialized);

  void Serialize(const UserProfile & profile, string * serialized);
  void Deserialize(const string & serialized, UserProfile * profile);
private:
  PoolManager pool_;
};

}
}
#endif // _XCE_USER_PROFILE_CLIENT_H_
