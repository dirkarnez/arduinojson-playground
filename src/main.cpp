#include <ArduinoJson.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
   DynamicJsonDocument doc(1024);

   // You can use a String as your JSON input.
   // WARNING: the string in the input  will be duplicated in the JsonDocument.
   string input = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
      
   deserializeJson(doc, input);
   JsonObject obj = doc.as<JsonObject>();

   // You can use a String to get an element of a JsonObject
   // No duplication is done.
   long time = obj[string("time")];

   // You can use a String to set an element of a JsonObject
   // WARNING: the content of the String will be duplicated in the JsonDocument.
   obj[string("time")] = time;

   // You can get a String from a JsonObject or JsonArray:
   // No duplication is done, at least not in the JsonDocument.
   string sensor = obj["sensor"];

   // Unfortunately, the following doesn't work (issue #118):
   // sensor = obj["sensor"]; // <-  error "ambiguous overload for 'operator='"
   // As a workaround, you need to replace by:
   sensor = obj["sensor"].as<string>();

   // You can set a String to a JsonObject or JsonArray:
   // WARNING: the content of the String will be duplicated in the JsonDocument.
   obj["sensor"] = sensor;

   // It works with serialized() too:
   obj["sensor"] = serialized(sensor);

   // You can also concatenate strings
   // WARNING: the content of the String will be duplicated in the JsonDocument.
   obj[string("sen") + "sor"] = string("gp") + "s";

   // You can compare the content of a JsonObject with a String
   if (obj["sensor"] == sensor)
   {
      // ...
   }

   // Lastly, you can print the resulting JSON to a String
   string output;
   serializeJson(doc, output);
   cout << output << endl;
   
   cin.get();
   return 0;
}