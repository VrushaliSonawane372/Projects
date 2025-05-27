import java.net.*;
import java.io.*;

class ServerChat {
    public static void main(String[] args) throws Exception {
        System.out.println("Server side running...");
        ServerSocket ssobj = new ServerSocket(2200);

        System.out.println("Waiting for client on port 2200...");
        Socket sobj = ssobj.accept();
        System.out.println("Client connected.");

        // Read option from client
        BufferedReader optionReader = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        int option = Integer.parseInt(optionReader.readLine());

        switch (option) {
            case 1:
                // Chatting logic
                PrintStream ps = new PrintStream(sobj.getOutputStream());
                BufferedReader b1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
                BufferedReader b2 = new BufferedReader(new InputStreamReader(System.in));

                String str1, str2;
                System.out.println("Chatting Application Starts...");

                while ((str1 = b1.readLine()) != null) {
                    System.out.println("Client says: " + str1);
                    System.out.print("Enter message for Client: ");
                    str2 = b2.readLine();
                    ps.println(str2);
                }

                ps.close();
                b1.close();
                b2.close();
                break;

            case 2:
                // File receiving logic
                DataInputStream dis = new DataInputStream(sobj.getInputStream());  //It receives and reads the message sent by the client
                FileOutputStream fos = new FileOutputStream("received_chatting.txt"); //creates a file (or opens it) and writes data to it.

                byte[] buffer = new byte[4096];
                int bytesRead;
                boolean fileReceived = false;

                while ((bytesRead = dis.read(buffer)) > 0) {
                    fos.write(buffer, 0, bytesRead);
                    fileReceived = true;
                }

                if (fileReceived) {
                    System.out.println("File received successfully and saved as 'received_chatting.txt'.");
                } else {
                    System.out.println("No file data received. Transfer failed or aborted.");
                }

                dis.close();
                fos.close();
                break;

            default:
                System.out.println("Invalid option received from client.");
        }

        sobj.close();
        ssobj.close();
    }
}