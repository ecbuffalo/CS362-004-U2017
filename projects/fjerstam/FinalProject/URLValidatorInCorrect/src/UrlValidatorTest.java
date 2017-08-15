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


import java.util.Random;

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
       System.out.println("****Random Testing*****");

       Random rand = new Random();
       int valid = 0;
       int notValid = 0;
       int invalid = 0;
       int notInvalid = 0;

       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

       String[] schemeValid = {"http://", "ftp://", "h3t://", ""};
       String[] schemeInvalid = {"3ht://", "http:/", "http:",  "http/", "://"};
       String[] authorityValid = {"www.google.com", "go.com", "go.au", "0.0.0.0", "255.255.255.255", "255.com", "go.cc"};
       String[] authorityInvalid = {"256.256.256.256", "1.2.3.4.5", "1.2.3.4.", "1.2.3", ".1.2.3.4", "go.a", "go.a1a",
               "go.1aa", "aaa.", ".aaa", "aaa", ""};
       String[] portValid = {":80", ":65535", ":0", "", ":65636"};
       String[] portInvalid = {":-1", ":65a"};
       String[] pathValid = {"/test1", "/t123", "/$23", "/test1/", "", "/test1/file"};
       String[] pathInvalid = {"/..", "/../", "/..//file", "/test1//file"};
       String[] query = {"?action=view", "?action=edit&mode=up", ""};

       for(int i = 0;i<10000;i++)
       {
           int schemeIndex = rand.nextInt(schemeValid.length);
           int authorityIndex = rand.nextInt(authorityValid.length);
           int portIndex = rand.nextInt(portValid.length);
           int pathIndex = rand.nextInt(pathValid.length);
           int queryIndex = rand.nextInt(query.length);
           System.out.println(urlVal.isValid(schemeValid[schemeIndex] + authorityValid[authorityIndex] + portValid[portIndex]
                   + pathValid[pathIndex] + query[queryIndex]));
           if(urlVal.isValid(schemeValid[schemeIndex] + authorityValid[authorityIndex] + portValid[portIndex]
                   + pathValid[pathIndex] + query[queryIndex])){
               valid++;
           } else notValid++;

           schemeIndex = rand.nextInt(schemeInvalid.length);
           authorityIndex = rand.nextInt(authorityInvalid.length);
           portIndex = rand.nextInt(portInvalid.length);
           pathIndex = rand.nextInt(pathInvalid.length);
           queryIndex = rand.nextInt(query.length);
           System.out.println(urlVal.isValid(schemeInvalid[schemeIndex] + authorityInvalid[authorityIndex] + portInvalid[portIndex]
                   + pathInvalid[pathIndex] + query[queryIndex]));
           if (urlVal.isValid(schemeInvalid[schemeIndex] + authorityInvalid[authorityIndex] + portInvalid[portIndex]
                   + pathInvalid[pathIndex] + query[queryIndex])) {
               notInvalid++;
           } else invalid++;
       }

       System.out.println("Valid Url test is valid " + valid + " times and invalid " + notValid + " times");
       System.out.println("Invalid Url test is valid " + notInvalid + " times and invalid " + invalid + " times");
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
