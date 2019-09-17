#pragma once

#include <ToolboxModule.h>
#include <ToolboxUIElement.h>
#include <discord_game_sdk/c/discord_game_sdk.h>

struct Application {
    struct IDiscordCore* core;
    struct IDiscordUserManager* users;
    struct IDiscordAchievementManager* achievements;
    struct IDiscordActivityManager* activities;
    struct IDiscordRelationshipManager* relationships;
    struct IDiscordApplicationManager* application;
    struct IDiscordLobbyManager* lobbies;
    struct IDiscordNetworkManager* network;
    DiscordUserId user_id;
};
// Encoded/decoded when joining another player's game.
struct DiscordJoinableParty {
    unsigned short map_id = 0;
    short district_id;
    short region_id;
    short language_id;
    wchar_t player[32];
};

class DiscordModule : public ToolboxModule {
    DiscordModule() {};
    ~DiscordModule() {};
public:
    static DiscordModule& Instance() {
        static DiscordModule instance;
        return instance;
    }

    const char* Name() const override { return "Discord"; }
    void Initialize() override;
    void Terminate() override;
    void Update(float delta) override;
    void LoadSettings(CSimpleIni* ini) override;
    void SaveSettings(CSimpleIni* ini) override;
    void DrawSettingInternal() override;

    void UpdateActivity();

    bool InviteUser(DiscordUser* user);
    void FailedJoin(const char* error_msg);
    void JoinParty();
    bool IsInJoinablePartyMap();

    Application app;
    DiscordActivity activity;

private:
    DiscordCreateParams params;
    
    IDiscordUserEvents users_events;
    IDiscordActivityEvents activities_events;
    IDiscordRelationshipEvents relationships_events;
    IDiscordNetworkEvents network_events;
    IDiscordCoreEvents core_events;
    

    // setting vars
    bool discord_enabled = true;
    bool hide_activity_when_offline = true;
    bool show_location_info = true;
    bool show_character_info = true;
    bool show_party_info = true;

    // runtime vars
    bool discord_connected = false;
    time_t zone_entered_time = 0;
    bool pending_activity_update = false;
    bool pending_discord_connect = true;
    std::wstring dll_location;
    time_t last_activity_update = 0;

    bool LoadDll();
    bool Connect();
    void Disconnect();
};