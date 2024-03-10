import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalTime;
import java.time.temporal.ChronoUnit;

public class Main {

    public static void main(String[] args) {

        if (args.length != 1) {
            System.out.println("Invalid arguments! Pass the input file name.");
            return;
        }

        String fileName = args[0];
        int[][] firstMatrix;
        int[][] secondMatrix;
        int[][] resultMatrix;
        String dataType;

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            // Load opcode
            int opcode = Integer.parseInt(reader.readLine());

            // Load data type
            dataType = reader.readLine().trim();

            // Load first matrix dimensions
            String line = reader.readLine();
            String[] dimensions = line.split("x");
            int firstMatrixRows = Integer.parseInt(dimensions[0]);
            int firstMatrixCols = Integer.parseInt(dimensions[1]);

            // Allocate memory for first matrix
            firstMatrix = new int[firstMatrixRows][firstMatrixCols];

            // Read first matrix data
            for (int i = 0; i < firstMatrixRows; i++) {
                line = reader.readLine();
                String[] values = line.split("\t");
                for (int j = 0; j < firstMatrixCols; j++) {
                    firstMatrix[i][j] = Integer.parseInt(values[j]);
                }
            }

            // Load second matrix dimensions
            line = reader.readLine();
            dimensions = line.split("x");
            int secondMatrixRows = Integer.parseInt(dimensions[0]);
            int secondMatrixCols = Integer.parseInt(dimensions[1]);

            // Allocate memory for second matrix
            secondMatrix = new int[secondMatrixRows][secondMatrixCols];

            // Read second matrix data
            for (int i = 0; i < secondMatrixRows; i++) {
                line = reader.readLine();
                String[] values = line.split("\t");
                for (int j = 0; j < secondMatrixCols; j++) {
                    secondMatrix[i][j] = Integer.parseInt(values[j]);
                }
            }

        } catch (IOException e) {
            System.out.println("Unable to open file for read: " + e.getMessage());
            return;
        }

        // Perform matrix multiplication
        resultMatrix = new int[firstMatrix.length][secondMatrix[0].length];

        LocalTime startTime = LocalTime.now();

        for (int i = 0; i < firstMatrix.length; i++) {
            for (int j = 0; j < secondMatrix[0].length; j++) {
                for (int k = 0; k < secondMatrix.length; k++) {
                    resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }
        LocalTime endTime = LocalTime.now();

        // Write the result to the file
        try (FileWriter writer = new FileWriter("result.txt")) {
            writer.write(dataType + "\n");
            writer.write(firstMatrix.length + "x" + secondMatrix[0].length + "\n");
            for (int i = 0; i < firstMatrix.length; i++) {
                for (int j = 0; j < secondMatrix[0].length; j++) {
                    writer.write(resultMatrix[i][j] + "\t");
                }
                writer.write("\n");
            }
        } catch (IOException e) {
            System.out.println("Unable to write to output file: " + e.getMessage());
            return;
        }

        long elapsed_time = startTime.until(endTime, ChronoUnit.SECONDS);

        System.out.println("Results written to result.txt");
        System.out.println("Time taken: " + elapsed_time + " seconds");
    }
}