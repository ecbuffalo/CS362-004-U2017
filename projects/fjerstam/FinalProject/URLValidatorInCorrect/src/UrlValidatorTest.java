/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(urlVal.isValid("http://amazon.com:0"));
	   System.out.println(urlVal.isValid("http://amazon.com:800"));
	   System.out.println(urlVal.isValid("http://amazon.com:80/page"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:80/page?test=1"));
	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
       System.out.println("******First Partition*******");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       String[] schemeValid = {"http://", "ftp://", "h3t://", ""};
       String[] schemeInvalid = {"3ht://", "http:/", "http:",  "http/", "://"};

       System.out.println("***Should be True***");
       for(int i = 0; i < schemeValid.length; i++) {
           System.out.println(urlVal.isValid(schemeValid[i] + "www.amazon.com"));
       }
       System.out.println("***Should be False***");
       for(int i = 0; i < schemeInvalid.length; i++) {
           System.out.println(urlVal.isValid(schemeInvalid[i] + "www.amazon.com"));
       }

   }
   
   public void testYourSecondPartition(){
       System.out.println("******Second Partition*******");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       String[] urlValid = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com", "go.cc"};
       String[] urlInvalid = {"256.256.256.256", "1.2.3.4.5", "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.a1a", "go.1aa", "aaa.", ".aaa", "aaa", ""};

       System.out.println("***Should be True***");
       for (int i = 0; i < urlValid.length; i++){
           System.out.println(urlVal.isValid("http://" + urlValid[i]));
       }

       System.out.println("***Should be False***");
       for (int i = 0; i < urlInvalid.length; i++){
           System.out.println(urlVal.isValid("http://" + urlInvalid[i]));
       }
	   
   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
