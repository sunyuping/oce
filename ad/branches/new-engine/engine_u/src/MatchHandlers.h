#ifndef AD_MACHER_HANDLERS_H_
#define AD_MACHER_HANDLERS_H_

#include <IceUtil/Shared.h>
#include <boost/algorithm/string/regex.hpp>
#include "AdEngine.h"
#include "AdStruct.h"
#include "AdConfig.h"
#include "../../util/src/AdCommonUtil.h"
//#include "AdEffect.h"

namespace xce {
namespace ad {

using namespace MyUtil;
using namespace std;
using namespace boost;


struct MatchHandlerParamter {
  MatchHandlerParamter(const UserProfile& userProfile,
                       const string& append_para):
                       userProfile_(userProfile), rotate_index_(0), photo_(false), has_re_(0) {
    vector < string > para_strs;
    boost::algorithm::split_regex(para_strs, append_para, regex("\\^C"));
    if (para_strs.size() >= 3) {
      referer_ = para_strs[0];
      next_load_time_ = para_strs[1];
      refresh_idx_ = para_strs[2];
    } else if (para_strs.size() >= 1) {
      referer_ = para_strs[0];
    }
  };

  unsigned int PickCount() const {  // 返回还需要选取的广告数
    if (EngineConfig::instance().IsForBrand()) {
      return adzone_->brand_count() - zone_selected_groups_.size();
    } else if(photo_ && adzone_->id() == 100000000072) {
      return EngineConfig::instance().photo_wb1_count() - zone_selected_groups_.size();
    } else {
      int cnt = adzone_->bp_count();
      if( style_ ){
        cnt = style_->ad_cnt();
      }
      return cnt - zone_selected_groups_.size();
    }
  }

  UserProfile userProfile_;
  string referer_;
  string next_load_time_;
  string refresh_idx_;
  AdStylePtr style_;
  AdZonePtr adzone_;
  int rotate_index_;
  set<SelectedAdGroupPtr> total_selected_groups_;
  set<SelectedAdGroupPtr> zone_selected_groups_;
  vector<SelectedAdGroupPtr> final_selected_groups_;
  bool has_re_;
  string tag_;
  bool photo_;
};

class AdMatchHandler : public IceUtil::Shared {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result) = 0;
};

class RotationHandler : public AdMatchHandler {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result);
};

class DefaultHandler : public AdMatchHandler {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result);
};

class PosAdjustHandler : public AdMatchHandler {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result);
};

class StyleHandler : public AdMatchHandler {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result);
public :
  bool isBig(int widget_id);
};

class LogHandler : public AdMatchHandler {
public:
  virtual bool handle(MatchHandlerParamter& para, AdResultMap& result);
};

}
}

#endif // AD_MACHER_HANDLERS_H_
