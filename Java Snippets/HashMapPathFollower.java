import java.util.*;

public class HashMapPathFollower {
  public static void main(String[] args) {
        int c = 12;
        HashMap b = new HashMap();
        b.put("c", c);
        HashMap a = new HashMap();
        a.put("b", b);
        HashMap obj = new HashMap();
        obj.put("a", a);

        // System.out.println(obj);
        // obj = {
        //     a: {
        //         b: {
        //             c: 12
        //         }
        //     }
        // };


        System.out.println(findPath(obj, "a:b:c")); // 12
        System.out.println(findPath(obj, "a:b")); // {c: 12}
        System.out.println(findPath(obj, "a")); // null
        System.out.println(findPath(obj, "a:c")); // null
        System.out.println(findPath(obj, "a:b:c:d")); // null
        System.out.println(findPath(obj, "a:b:c:d:e")); // null
  }
  
  public static Object findPath(HashMap obj, String path) {
      String[] keyArr = path.split(":");
      Object result = obj;

      for(String key: keyArr) {
          if (obj.containsKey(key)) {
            if (obj.get(key) instanceof HashMap) {
              obj = (HashMap) obj.get(key);
              result = obj;
            } else {
              result = obj.get(key);
            }
          } else {
              result = null;
              break;
          }
      }

      return result;
  }
}
