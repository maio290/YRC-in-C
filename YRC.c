#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>



void cURL_XML_POST(char* url, char *command)
{

	CURL *cURL = curl_easy_init();
	
	if(cURL)
	{
		struct curl_slist *slist = NULL;
		
		slist = curl_slist_append(slist,"Accept: */*");
		slist = curl_slist_append(slist,"Content-Type: text/xml");
		curl_easy_setopt(cURL, CURLOPT_CUSTOMREQUEST, "POST /YamahaRemoteControl/ctrl");
		curl_easy_setopt(cURL, CURLINFO_HEADER_OUT, 1L);
		curl_easy_setopt(cURL, CURLOPT_USERAGENT,  "YRC");
		curl_easy_setopt(cURL, CURLOPT_HTTPHEADER, slist);
		curl_easy_setopt(cURL, CURLOPT_URL, url);
		curl_easy_setopt(cURL, CURLOPT_POSTFIELDS, command);
		curl_easy_perform(cURL);
		curl_slist_free_all(slist);
		free(cURL);
	}
	

}


int main (int argc, char* argv[]) 
{
	
	char *ip = argv[1];
	char *url = malloc(strlen(ip)+strlen("http:///YamahaRemoteControl/ctrl")-1);
	
	url = strcat(strcat(strcat(url,"http://"),ip),"/YamahaRemoteControl/ctrl")+3;
	
	
	char *command = malloc(1024);
	
	for (int i = 2; i<argc; i++)
	{
		
		
		command = malloc(1024);
		
		if(strcmp(argv[i],"-power_on") == 0)
		{
		cURL_XML_POST(url,"<YAMAHA_AV cmd=\"PUT\"><Main_Zone><Power_Control><Power>On</Power></Power_Control></Main_Zone></YAMAHA_AV>");
		}
		if(strcmp(argv[i],"-power_off") == 0)
		{
		cURL_XML_POST(url,"<YAMAHA_AV cmd=\"PUT\"><Main_Zone><Power_Control><Power>Standby</Power></Power_Control></Main_Zone></YAMAHA_AV>");
		}
		if(strcmp(argv[i],"-input") == 0)
		{
		command = strcat(strcat(strcat(command,"<YAMAHA_AV cmd=\"PUT\"><Main_Zone><Input><Input_Sel>"),argv[++i]),"</Input_Sel></Input></Main_Zone></YAMAHA_AV>");
		cURL_XML_POST(url,command);
		}
		if(strcmp(argv[i],"-setvol") == 0)
		{		
		command = strcat(strcat(strcat(command,"<YAMAHA_AV cmd=\"PUT\"><Main_Zone><Volume><Lvl><Val>-"),argv[++i]),"</Val><Exp>1</Exp><Unit>dB</Unit></Lvl></Volume></Main_Zone></YAMAHA_AV>");
		cURL_XML_POST(url,command);		
		}
		
		free(command);
		
		if(i >= argc)
		{
			break;
		}
		
		
		
	}

}
