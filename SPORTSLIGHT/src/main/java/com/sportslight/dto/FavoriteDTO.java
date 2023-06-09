package com.sportslight.dto;

import org.springframework.stereotype.Component;

import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Component
@Getter
@Setter
@NoArgsConstructor
public class FavoriteDTO {
	
	private int favoriteNum;
	private int memberNum;
	private int videoNum;
	private String videoName;
	private String thumbnailUrl;

}
