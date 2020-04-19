#include "GameConfiguration.h"

/* Khi đặt static member phải khởi tạo như vậy */
map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


/* Lấy 1 thống số ra từ 1 key cho trước */
double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		/* window_width, window_height là kích thước cửa sổ */
		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));

		/* backbuffer_width, backbuffer_height là kích thước của backbuffer */
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 250));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));

		/* fps là frame_per_second càng lớn càng mượt nhưng nó sử dụng nhiều cpu hơn */
		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));

		/* thời gian đổi frame mặc định của animation là 100 milis, cứ sau 100 milis thì animation sẽ đổi 1 frame */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default",70));

		/* trọng lực mặc định của đối tượng 80 (px/s^2) */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_default_ay", -750));

		globalsConfigurationDouble->insert(pair<const char*, double>("bat_ay", -100));

		/*  PLAYER  */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 80)); /* 60 pixel/s */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vy_jump", 300)); /* 60 pixel/s */
		/* vx của player khi lên stair */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_stair_dx", 1));//1 pixel/ frame */
		/* vy của player khi lên stair */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_stair_dy", 1)); /* 1 pixel/ frame */


		globalsConfigurationDouble->insert(pair<const char*, double>("leopart_run_dx", 50));  
		globalsConfigurationDouble->insert(pair<const char*, double>("leopart_jump_vy", 180)); 
		globalsConfigurationDouble->insert(pair<const char*, double>("leopart_run_vx", 80)); 
		globalsConfigurationDouble->insert(pair<const char*, double>("zoombie_run_vx", 30));
		globalsConfigurationDouble->insert(pair<const char*, double>("zoombie_run_dx", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("zoombie_run_dx_to_turning", 400));

		globalsConfigurationDouble->insert(pair<const char*, double>("blacknight_vx", 50));
		globalsConfigurationDouble->insert(pair<const char*, double>("bat_run_dx", 80));

		globalsConfigurationDouble->insert(pair<const char*, double>("fleaman_jumpshort_counter", 2));
		globalsConfigurationDouble->insert(pair<const char*, double>("fleaman_jumplong_counter", 1));
		globalsConfigurationDouble->insert(pair<const char*, double>("fleaman_vy_short", 120));
		globalsConfigurationDouble->insert(pair<const char*, double>("fleaman_vy_long", 220));
		globalsConfigurationDouble->insert(pair<const char*, double>("fleaman_vx", 30));

		globalsConfigurationDouble->insert(pair<const char*, double>("die_effect_time", 500));
		
	}
	/* trả ra giá trị cấu hình tại key */
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	/* Hướng dẫn: Đọc singleton pattern để hiểu cách viết này */
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		/* Tiêu đề của cửa sổ */
		globalsConfigurationString->insert(pair<const char*,const char*>("window_title", "Game"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));

	}
	/* trả ra giá trị cấu hình tại key */
	return globalsConfigurationString->at(key);
}

GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}
