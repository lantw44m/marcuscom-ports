--- plugins/calendar-weather/calendar-weather.c.orig	Thu Feb 10 11:27:00 2005
+++ plugins/calendar-weather/calendar-weather.c	Thu Feb 10 11:29:47 2005
@@ -57,13 +57,13 @@
 		}
 	}
 	if (!found) {
-		e_categories_add (_("Weather: Cloudy"), NULL, WEATHER_DATADIR "/category_weather_cloudy_16.png");
-		e_categories_add (_("Weather: Fog"), NULL, WEATHER_DATADIR "/category_weather_fog_16.png");
-		e_categories_add (_("Weather: Partly Cloudy"), NULL, WEATHER_DATADIR "/category_weather_partly_cloudy_16.png");
-		e_categories_add (_("Weather: Rain"), NULL, WEATHER_DATADIR "/category_weather_rain_16.png");
-		e_categories_add (_("Weather: Snow"), NULL, WEATHER_DATADIR "/category_weather_snow_16.png");
-		e_categories_add (_("Weather: Sunny"), NULL, WEATHER_DATADIR "/category_weather_sun_16.png");
-		e_categories_add (_("Weather: Thunderstorms"), NULL, WEATHER_DATADIR "/category_weather_tstorm_16.png");
+		e_categories_add (_("Weather: Cloudy"), NULL, WEATHER_DATADIR "/category_weather_cloudy_16.png", FALSE);
+		e_categories_add (_("Weather: Fog"), NULL, WEATHER_DATADIR "/category_weather_fog_16.png", FALSE);
+		e_categories_add (_("Weather: Partly Cloudy"), NULL, WEATHER_DATADIR "/category_weather_partly_cloudy_16.png", FALSE);
+		e_categories_add (_("Weather: Rain"), NULL, WEATHER_DATADIR "/category_weather_rain_16.png", FALSE);
+		e_categories_add (_("Weather: Snow"), NULL, WEATHER_DATADIR "/category_weather_snow_16.png", FALSE);
+		e_categories_add (_("Weather: Sunny"), NULL, WEATHER_DATADIR "/category_weather_sun_16.png", FALSE);
+		e_categories_add (_("Weather: Thunderstorms"), NULL, WEATHER_DATADIR "/category_weather_tstorm_16.png", FALSE);
 	}
 
 	return 0;
