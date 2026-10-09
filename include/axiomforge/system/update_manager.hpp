#pragma once
#include <string>
namespace axf {
struct UpdateStatus { std::string current_version,channel,latest_known_version; bool update_available{false}; };
class UpdateManager {
public:
 explicit UpdateManager(std::string current_version);
 UpdateStatus status() const;
 bool validate_patch_manifest(const std::string& manifest_path,std::string& error) const;
private: std::string current_version_;
};
}
