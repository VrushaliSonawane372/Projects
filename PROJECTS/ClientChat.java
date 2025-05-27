import java.net.*;
import java.io.*;
import java.util.*;

class ClientChat {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // Ask user for option
        System.out.println("Enter 1 for chatting and 2 for file transfer:");
        int option = sc.nextInt();
        sc.nextLine(); // Consume newline

        // Connect to server
        Socket sobj = new Socket("localhost", 2200);
        System.out.println("Connected to server.");

        // Send option to server
        PrintWriter optionWriter = new PrintWriter(sobj.getOutputStream(), true);
        optionWriter.println(option);

        switch (option) {
            case 1:
                // Chatting logic
                PrintStream ps = new PrintStream(sobj.getOutputStream());
                BufferedReader fromServer = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
                BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));

                String str1, str2;
                System.out.println("Chat Application Starts... Type 'stop' to end chat.");

                while (!(str1 = fromUser.readLine()).equalsIgnoreCase("stop")) {
                    ps.println(str1);  // send message to server
                    str2 = fromServer.readLine();  // receive reply
                    System.out.println("Server says: " + str2);
                    System.out.println("Enter message for Server:");
                }

                System.out.println("End of chat.");
                ps.close();
                fromServer.close();
                fromUser.close();
                break;

            case 2:
                // File transfer logic
                System.out.print("Enter file name to send: ");
                String fileName = sc.nextLine();

                File file = new File(fileName);
                if (!file.exists()) {
                    System.out.println("File not found. Exiting...");
                    sobj.close();
                    return;
                }

                FileInputStream fis = new FileInputStream(file);
                DataOutputStream dos = new DataOutputStream(sobj.getOutputStream()); //It sends a text message over a network to the server.

                byte[] buffer = new byte[4096];
                int bytesRead;

                while ((bytesRead = fis.read(buffer)) > 0) {
                    dos.write(buffer, 0, bytesRead);
                }

                System.out.println("File sent successfully.");
                fis.close();
                dos.close();
                break;

            default:
                System.out.println("Invalid option.");
        }

        sobj.close();
        sc.close();
    }
}