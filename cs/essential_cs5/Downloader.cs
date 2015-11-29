using System;
using System.IO;
using System.Net;

class Downloader
{
    static int Main(string[] args)
    {
        int result;
        string targetFileName;
        string url;
        switch (args.Length)
        {
            default:
                // Exactly two arguments must be specified; gives an error.
                Console.WriteLine(
                        "ERROR: You must specify the "
                        + "URL and the file name");
                targetFileName = null;
                url = null;
                break;
            case 2:
                url = args[0];
                targetFileName = args[1];
                break;
        }

        if (targetFileName != null && url != null)
        {
            WebClient webClient = new WebClient();
            webClient.DownloadFile(url, targetFileName);
            result = 0;
        }
        else
        {
            Console.WriteLine(
                    "Usage: Downloader.exe <URL> <TargetFileName>");
            result = 1;
        }

        return result;
    }
}
