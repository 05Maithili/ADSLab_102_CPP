public class MoveZeroesToEnd {
    
    // Function to move all zeroes to the end of the array
    public static void moveZeroes(int[] arr) {
        int count = 0;  // Position to place next non-zero element

        // Step 1: Move all non-zero elements to the front
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                arr[count] = arr[i];
                count++;
            }
        }

        // Step 2: Fill the rest of the array with zeroes
        while (count < arr.length) {
            arr[count] = 0;
            count++;
        }
    }

    // Main method
    public static void main(String[] args) {
        int[] arr = {0, 1, 0, 3, 12};

        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        // Call the function to move zeroes
        moveZeroes(arr);

        System.out.println("\n\nArray after moving zeroes to end:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}