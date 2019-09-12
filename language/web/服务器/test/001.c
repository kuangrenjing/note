#include <stdio.h>
#include <unistd.h>
#include <string.h>
 #include <stdlib.h>

int main()
{
	char strTest[1024];
	char *pstrEnv;

	snprintf(strTest, 1024, "Status:404");
	write(STDOUT_FILENO, strTest, strlen(strTest));

	snprintf(strTest, 1024, "Content-Type:text/html\r\n\r\n");
	write(STDOUT_FILENO, strTest, strlen(strTest));

	snprintf(strTest, 1024, "<html><head>\n<title>cgi</title>\n</head>\n<body>\n");
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("REQUEST_METHOD");
	snprintf(strTest, 1024, "<p>REQUEST_METHOD:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("QUERY_STRING");
	snprintf(strTest, 1024, "<p>QUERY_STRING:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("CONTENT_LENGTH");
	snprintf(strTest, 1024, "<p>CONTENT_LENGTH:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("CONTENT_TYPE");
	snprintf(strTest, 1024, "<p>CONTENT_TYPE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("CONTENT_FILE");
	snprintf(strTest, 1024, "<p>CONTENT_FILE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("PATH_INFO");
	snprintf(strTest, 1024, "<p>PATH_INFO:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("PATH_TRANSLATED");
	snprintf(strTest, 1024, "<p>PATH_TRANSLATED:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("SCRIPT_NAME");
	snprintf(strTest, 1024, "<p>SCRIPT_NAME:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("GATEWAY_INTERFACE");
	snprintf(strTest, 1024, "<p>GATEWAY_INTERFACE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("SERVER_NAME");
	snprintf(strTest, 1024, "<p>SERVER_NAME:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("SERVER_PORT");
	snprintf(strTest, 1024, "<p>SERVER_PORT:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("SERVER_SOFTWARE");
	snprintf(strTest, 1024, "<p>SERVER_SOFTWARE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("REMOTE_ADDR");
	snprintf(strTest, 1024, "<p>REMOTE_ADDR:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("REMOTE_HOST");
	snprintf(strTest, 1024, "<p>REMOTE_HOST:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("ACCEPT");
	snprintf(strTest, 1024, "<p>ACCEPT:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("ACCEPT_ENCODING");
	snprintf(strTest, 1024, "<p>ACCEPT_ENCODING:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("ACCEPT_LANGUAGE");
	snprintf(strTest, 1024, "<p>ACCEPT_LANGUAGE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("AUTORIZATION");
	snprintf(strTest, 1024, "<p>AUTORIZATION:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("FORM");
	snprintf(strTest, 1024, "<p>FORM:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("IF_MODIFIED_SINGCE");
	snprintf(strTest, 1024, "<p>IF_MODIFIED_SINGCE:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("PRAGMA");
	snprintf(strTest, 1024, "<p>PRAGMA:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));


	pstrEnv = getenv("REFFERER");
	snprintf(strTest, 1024, "<p>REFFERER:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	pstrEnv = getenv("HTTP_ACCEPT");
	snprintf(strTest, 1024, "<p>HTTP_ACCEPT:%s</p>", pstrEnv);
	write(STDOUT_FILENO, strTest, strlen(strTest));

	snprintf(strTest, 1024, "<p>hello world</p>");
	write(STDOUT_FILENO, strTest, strlen(strTest));

	snprintf(strTest, 1024, "</body></html>");
	write(STDOUT_FILENO, strTest, strlen(strTest));



	return 0;
}