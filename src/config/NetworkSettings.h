#pragma once

#include "ConfigValue.h"
#include "XMLConfig.h"


enum class NetworkService {
Nintendo,
Pretendo,
Custom,
};
struct NetworkConfig {
    NetworkConfig()
	{

	};

	NetworkConfig(const NetworkConfig&) = delete;

    ConfigValue<std::string> networkname;
    ConfigValue<bool> disablesslver = false;
    struct
	{
		 ConfigValue<std::string> ACT;
		 ConfigValue<std::string> ECS;
		 ConfigValue<std::string> NUS;
		 ConfigValue<std::string> IAS;
		 ConfigValue<std::string> CCSU;
		 ConfigValue<std::string> CCS;
		 ConfigValue<std::string> IDBE;
		 ConfigValue<std::string> BOSS;
		 ConfigValue<std::string> TAGAYA;
		 ConfigValue<std::string> OLV;
	}urls{};

    public:
    static void LoadOnce();
    void Load(XMLConfigParser& parser);
    void Save(XMLConfigParser& parser);
    
    static bool XMLExists();
};

struct NintendoURLs {
   inline static std::string ACTURL = "https://account.nintendo.net";
   inline static std::string ECSURL = "https://ecs.wup.shop.nintendo.net/ecs/services/ECommerceSOAP";
   inline static std::string NUSURL = "https://nus.wup.shop.nintendo.net/nus/services/NetUpdateSOAP";
   inline static std::string IASURL = "https://ias.wup.shop.nintendo.net/ias/services/IdentityAuthenticationSOAP";
   inline static std::string CCSUURL = "https://ccs.wup.shop.nintendo.net/ccs/download";
   inline static std::string CCSURL = "http://ccs.cdn.wup.shop.nintendo.net/ccs/download";
   inline static std::string IDBEURL = "https://idbe-wup.cdn.nintendo.net/icondata";
   inline static std::string BOSSURL = "https://npts.app.nintendo.net/p01/tasksheet";
   inline static std::string TAGAYAURL = "https://tagaya.wup.shop.nintendo.net/tagaya/versionlist";
   inline static std::string OLVURL = "https://discovery.olv.nintendo.net/v1/endpoint";
};

struct PretendoURLs {
   inline static std::string ACTURL = "https://account.nintendo.net";
   inline static std::string ECSURL = "https://ecs.wup.shop.nintendo.net/ecs/services/ECommerceSOAP";
   inline static std::string NUSURL = "https://nus.wup.shop.nintendo.net/nus/services/NetUpdateSOAP";
   inline static std::string IASURL = "https://ias.wup.shop.nintendo.net/ias/services/IdentityAuthenticationSOAP";
   inline static std::string CCSUURL = "https://ccs.wup.shop.nintendo.net/ccs/download";
   inline static std::string CCSURL = "http://ccs.cdn.wup.shop.nintendo.net/ccs/download";
   inline static std::string IDBEURL = "https://idbe-wup.cdn.nintendo.net/icondata";
   inline static std::string BOSSURL = "https://npts.app.nintendo.net/p01/tasksheet";
   inline static std::string TAGAYAURL = "https://tagaya.wup.shop.nintendo.net/tagaya/versionlist";
   inline static std::string OLVURL = "https://olvdisc.nonamegiven.xyz/v1/endpoint";
};

typedef XMLDataConfig<NetworkConfig, &NetworkConfig::Load, &NetworkConfig::Save> XMLNetworkConfig_t;
extern XMLNetworkConfig_t n_config;
inline NetworkConfig& GetNetworkConfig() { return n_config.data();};