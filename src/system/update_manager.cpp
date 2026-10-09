#include "axiomforge/system/update_manager.hpp"
#include <fstream>
#include <iterator>
#include <utility>
namespace axf {
UpdateManager::UpdateManager(std::string v):current_version_(std::move(v)){}
UpdateStatus UpdateManager::status()const{return{current_version_,"development",current_version_,false};}
bool UpdateManager::validate_patch_manifest(const std::string& path,std::string& error)const{std::ifstream f(path);if(!f){error="Patch manifest not found: "+path;return false;}std::string content((std::istreambuf_iterator<char>(f)),{});if(content.find("\"patch_id\"")==std::string::npos||content.find("\"target_version\"")==std::string::npos){error="Patch manifest must contain patch_id and target_version";return false;}error.clear();return true;}
}
