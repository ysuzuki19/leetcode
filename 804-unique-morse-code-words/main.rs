use std::collections::HashMap;

const morse: &[&str] = &[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];

fn to_index(b: u8) -> usize {
  (b as usize) - 97
}

fn transform(word: String) -> String {
  let mut series = String::new();
  for b in word.bytes() {
    let i = to_index(b);
    series.push_str(&morse[i].to_string());
  }
  series
}

impl Solution {
  pub fn unique_morse_representations(words: Vec<String>) -> i32 {
    let mut map: HashMap<String, i64> = HashMap::new();
    for word in words {
      let series = transform(word);
      let entry = map.entry(series).or_insert(0);
      *entry += 1;
    }
    map.len() as i32
  }
}