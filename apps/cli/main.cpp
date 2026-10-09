#include "axiomforge/build_info.hpp"
#include "axiomforge/core/graph.hpp"
#include "axiomforge/core/query.hpp"
#include <iostream>
#include <string>
int main(){auto graph=axf::make_default_graph();axf::QueryEngine engine(graph);std::cout<<AXIOMFORGE_APP_NAME<<" "<<AXIOMFORGE_VERSION<<" (build "<<AXIOMFORGE_BUILD_NUMBER<<")\nType help for commands.\n";std::string line;while(std::cout<<"> "&&std::getline(std::cin,line)){if(line=="quit"||line=="exit")break;if(line=="about"){std::cout<<AXIOMFORGE_APP_NAME<<" by "<<AXIOMFORGE_DEVELOPER_NAME<<"\n";continue;}if(line=="build-info"){std::cout<<"build_number="<<AXIOMFORGE_BUILD_NUMBER<<"; product_id="<<AXIOMFORGE_PRODUCT_ID<<"\n";continue;}std::cout<<engine.execute(line)<<"\n";}return 0;}
