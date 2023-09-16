// https://algo.monster/problems/largest_k_positive_and_negative
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
class Solution {
    public static int largestK(List<Integer> nums) {
        HashSet<Integer>set = new HashSet<>();
        int maxi = 0;
        for(int a:nums){
        if(set.contains(-a)){
            maxi = Math.max(maxi,Math.abs(a));
        }else{
            set.add(a);
        }
        }
        return maxi;
    }

    public static List<String> splitWords(String s) {
        return s.isEmpty() ? List.of() : Arrays.asList(s.split(" "));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = splitWords(scanner.nextLine()).stream().map(Integer::parseInt).collect(Collectors.toList());
        scanner.close();
        int res = largestK(nums);
        System.out.println(res);
    }
}
