using System;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;


public class NetworkHandler :  MonoBehaviour {
void Start() {
    
}


private void Update()
{
    if (Input.GetKeyDown(KeyCode.W))
    {
        print("cliked");
        StartCoroutine(Upload("(170)(170)"));
    }
        if (Input.GetKeyDown(KeyCode.S))
        {
            print("cliked");
            StartCoroutine(Upload("(-170)(-170)"));
        }
}

IEnumerator Upload(String inp) {
    print("sent");
    WWWForm form = new WWWForm();
    form.AddField("State", inp);
 
    UnityWebRequest www = UnityWebRequest.Post("192.168.4.1", form);
    yield return www.SendWebRequest();
 
    if(www.isNetworkError || www.isHttpError) {
        Debug.Log(www.error);
    }
    else {
        Debug.Log("Form upload complete!");
    }
}
}